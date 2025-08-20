#include "mcc_generated_files/comparator/cmp2.h"
#include "mcc_generated_files/dac/dac2.h"
#include "mcc_generated_files/i2c_client/i2c1.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/TMR0.h"

/**
 * Global variables and definitions
 */

#define TICKS_IN_1_MS                                                          \
  8000 // 64 mhz clock, 1:8 prescaler so 8mhz clock, 1 ms = 8000 ticks
#define TIMER_PERIOD_MS                                                        \
  5 // Timer period in milliseconds, defined in MCC for both timers

// We keep track of everything twice:
// one for the left wheel and one for the right wheel
volatile uint32_t last_timer_capture_left = 0;
volatile uint32_t last_timer_capture_right = 0;
volatile uint16_t timeout_count_left = 0;
volatile uint16_t timeout_count_right = 0;
volatile uint16_t sequence_number_left = 0;
volatile uint16_t sequence_number_right = 0;
volatile bool edge_detected_left = false;
volatile bool edge_detected_right = false;
// I2C register map - 256 bytes of addressable space
static uint8_t register_map[256] = {0x0};
static uint8_t current_register = 0;
static bool register_received = false;

/**
 * Callback functions for the interrupts and events
 */

void OnCmp1Edge(void) {
  if (CMP1_GetOutputStatus()) // Only on rising edge
  {
    edge_detected_left = true;
    last_timer_capture_left =
        TMR0_CounterGet() +
        (TICKS_IN_1_MS * TIMER_PERIOD_MS * timeout_count_left);

    TMR0_CounterSet(0);
    timeout_count_left = 0;
    sequence_number_left++;
  } else {
    edge_detected_left = false;
  }
}

void OnCmp2Edge(void) {
  if (CMP2_GetOutputStatus()) // Only on rising edge
  {
    edge_detected_right = true;
    last_timer_capture_right =
        TMR1_CounterGet() +
        (TICKS_IN_1_MS * TIMER_PERIOD_MS * timeout_count_right);

    TMR1_CounterSet(0);
    timeout_count_right = 0;
    sequence_number_right++;
  } else {
    edge_detected_right = false;
  }
}

bool OnI2CEvent(i2c_client_transfer_event_t event) {
  switch (event) {
  case I2C_CLIENT_TRANSFER_EVENT_ADDR_MATCH:
    // Address matched - prepare for data transfer
    register_received = false;

    // Update the registers that will be sent back for this request
    // according to the register map, little endian

    // DISABLE interrupts for atomic register update
    INTERRUPT_GlobalInterruptDisable();

    // Create local copies of volatile variables
    uint32_t local_capture_left = last_timer_capture_left;
    uint32_t local_capture_right = last_timer_capture_right;
    uint16_t local_timeout_left = timeout_count_left;
    uint16_t local_timeout_right = timeout_count_right;
    uint16_t local_seq_left = sequence_number_left;
    uint16_t local_seq_right = sequence_number_right;

    // RE-ENABLE interrupts immediately
    INTERRUPT_GlobalInterruptEnable();

    // Update the register map with the latest values
    register_map[0x02] = (uint8_t)(local_capture_left >> 24);
    register_map[0x03] = (uint8_t)(local_capture_left >> 16);
    register_map[0x04] = (uint8_t)(local_capture_left >> 8);
    register_map[0x05] = (uint8_t)(local_capture_left & 0xFF);

    register_map[0x06] = (uint8_t)(local_capture_right >> 24);
    register_map[0x07] = (uint8_t)(local_capture_right >> 16);
    register_map[0x08] = (uint8_t)(local_capture_right >> 8);
    register_map[0x09] = (uint8_t)(local_capture_right & 0xFF);

    register_map[0x0A] = (uint8_t)(local_timeout_left >> 8);
    register_map[0x0B] = (uint8_t)(local_timeout_left & 0xFF);

    register_map[0x0C] = (uint8_t)(local_timeout_right >> 8);
    register_map[0x0D] = (uint8_t)(local_timeout_right & 0xFF);

    register_map[0x0E] = (uint8_t)(local_seq_left >> 8);
    register_map[0x0F] = (uint8_t)(local_seq_left & 0xFF);

    register_map[0x10] = (uint8_t)(local_seq_right >> 8);
    register_map[0x11] = (uint8_t)(local_seq_right & 0xFF);
    break;

  case I2C_CLIENT_TRANSFER_EVENT_RX_READY:
    // Master is writing to us - this is the register address
    current_register = I2C1_ReadByte();
    register_received = true;
    break;

  case I2C_CLIENT_TRANSFER_EVENT_TX_READY:
    // Always send from register map, starting from current_register
    I2C1_WriteByte(register_map[current_register]);
    current_register++; // Auto-increment for sequential reads
    break;

  case I2C_CLIENT_TRANSFER_EVENT_STOP_BIT_RECEIVED:
    // Transaction complete
    register_received = false;
    break;

  case I2C_CLIENT_TRANSFER_EVENT_ERROR:
    // Handle I2C error
    register_received = false;
    break;

  case I2C_CLIENT_TRANSFER_EVENT_NONE:
  default:
    // No action needed
    break;
  }

  return true; // Continue processing
}

void OnTimer0Overflow(void) { timeout_count_left++; }

void OnTimer1Overflow(void) { timeout_count_right++; }

/**
 * Main code
 */

void main(void) {
  // This initializes the hardware (CMP1, CMP2, DAC2, I2C1, Timers, etc.) -
  // generated by MCC
  SYSTEM_Initialize();

  // Set the reference voltage for the only DAC (used by both CMP1 and CMP2)
  // value is between 0 and 255, where 0 is 0V and 255 is 5V
  DAC2_SetOutput(128); // ~ 2.5V reference voltage

  // Interrupts and callback registration
  INTERRUPT_GlobalInterruptEnable();
  CMP1_InterruptCallbackRegister(OnCmp1Edge);
  CMP2_InterruptCallbackRegister(OnCmp2Edge);
  I2C1_CallbackRegister(OnI2CEvent);
  TMR0_OverflowCallbackRegister(OnTimer0Overflow);
  TMR1_OverflowCallbackRegister(OnTimer1Overflow);

  // Fire the timers!
  TMR0_Start();
  TMR1_Start();

  // As a sanity check, the first two registers should always contain 0xbabe
  register_map[0x00] = 0xBA;
  register_map[0x01] = 0xBE;

  while (1) {
    // if (!edge_detected_left) {
    //   LED_SetLow(); // Turn LED off if no pulse received
    // } else {
    //   LED_SetHigh(); // Turn LED on to indicate RPM event
    // }
    __delay_ms(1);
  }
}
