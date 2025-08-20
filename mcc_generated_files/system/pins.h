/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define PGD_TRIS                 TRISAbits.TRISA0
#define PGD_LAT                  LATAbits.LATA0
#define PGD_PORT                 PORTAbits.RA0
#define PGD_WPU                  WPUAbits.WPUA0
#define PGD_OD                   ODCONAbits.ODCA0
#define PGD_ANS                  ANSELAbits.ANSELA0
#define PGD_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PGD_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PGD_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PGD_GetValue()           PORTAbits.RA0
#define PGD_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PGD_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PGD_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PGD_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PGD_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define PGD_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define PGD_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define PGD_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define PGC_TRIS                 TRISAbits.TRISA1
#define PGC_LAT                  LATAbits.LATA1
#define PGC_PORT                 PORTAbits.RA1
#define PGC_WPU                  WPUAbits.WPUA1
#define PGC_OD                   ODCONAbits.ODCA1
#define PGC_ANS                  ANSELAbits.ANSELA1
#define PGC_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PGC_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PGC_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PGC_GetValue()           PORTAbits.RA1
#define PGC_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PGC_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PGC_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PGC_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PGC_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PGC_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PGC_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define PGC_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSELA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 aliases
#define RXD1_TRIS                 TRISAbits.TRISA4
#define RXD1_LAT                  LATAbits.LATA4
#define RXD1_PORT                 PORTAbits.RA4
#define RXD1_WPU                  WPUAbits.WPUA4
#define RXD1_OD                   ODCONAbits.ODCA4
#define RXD1_ANS                  ANSELAbits.ANSELA4
#define RXD1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RXD1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RXD1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RXD1_GetValue()           PORTAbits.RA4
#define RXD1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RXD1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RXD1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RXD1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RXD1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RXD1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RXD1_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RXD1_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define TXD1_TRIS                 TRISAbits.TRISA5
#define TXD1_LAT                  LATAbits.LATA5
#define TXD1_PORT                 PORTAbits.RA5
#define TXD1_WPU                  WPUAbits.WPUA5
#define TXD1_OD                   ODCONAbits.ODCA5
#define TXD1_ANS                  ANSELAbits.ANSELA5
#define TXD1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define TXD1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define TXD1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define TXD1_GetValue()           PORTAbits.RA5
#define TXD1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define TXD1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define TXD1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define TXD1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define TXD1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define TXD1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define TXD1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define TXD1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RC0 aliases
#define SCL1_TRIS                 TRISCbits.TRISC0
#define SCL1_LAT                  LATCbits.LATC0
#define SCL1_PORT                 PORTCbits.RC0
#define SCL1_WPU                  WPUCbits.WPUC0
#define SCL1_OD                   ODCONCbits.ODCC0
#define SCL1_ANS                  ANSELCbits.ANSELC0
#define SCL1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCL1_GetValue()           PORTCbits.RC0
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC1
#define SDA1_LAT                  LATCbits.LATC1
#define SDA1_PORT                 PORTCbits.RC1
#define SDA1_WPU                  WPUCbits.WPUC1
#define SDA1_OD                   ODCONCbits.ODCC1
#define SDA1_ANS                  ANSELCbits.ANSELC1
#define SDA1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDA1_GetValue()           PORTCbits.RC1
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define CMP1N_TRIS                 TRISCbits.TRISC2
#define CMP1N_LAT                  LATCbits.LATC2
#define CMP1N_PORT                 PORTCbits.RC2
#define CMP1N_WPU                  WPUCbits.WPUC2
#define CMP1N_OD                   ODCONCbits.ODCC2
#define CMP1N_ANS                  ANSELCbits.ANSELC2
#define CMP1N_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define CMP1N_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define CMP1N_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define CMP1N_GetValue()           PORTCbits.RC2
#define CMP1N_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define CMP1N_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define CMP1N_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define CMP1N_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define CMP1N_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define CMP1N_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define CMP1N_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define CMP1N_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define CMP2N_TRIS                 TRISCbits.TRISC3
#define CMP2N_LAT                  LATCbits.LATC3
#define CMP2N_PORT                 PORTCbits.RC3
#define CMP2N_WPU                  WPUCbits.WPUC3
#define CMP2N_OD                   ODCONCbits.ODCC3
#define CMP2N_ANS                  ANSELCbits.ANSELC3
#define CMP2N_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CMP2N_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CMP2N_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CMP2N_GetValue()           PORTCbits.RC3
#define CMP2N_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CMP2N_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CMP2N_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define CMP2N_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define CMP2N_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define CMP2N_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define CMP2N_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define CMP2N_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define ENC_EN_TRIS                 TRISCbits.TRISC4
#define ENC_EN_LAT                  LATCbits.LATC4
#define ENC_EN_PORT                 PORTCbits.RC4
#define ENC_EN_WPU                  WPUCbits.WPUC4
#define ENC_EN_OD                   ODCONCbits.ODCC4
#define ENC_EN_ANS                  ANSELCbits.ANSELC4
#define ENC_EN_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ENC_EN_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ENC_EN_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ENC_EN_GetValue()           PORTCbits.RC4
#define ENC_EN_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ENC_EN_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define ENC_EN_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define ENC_EN_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define ENC_EN_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define ENC_EN_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define ENC_EN_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define ENC_EN_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define GPIO_C5_TRIS                 TRISCbits.TRISC5
#define GPIO_C5_LAT                  LATCbits.LATC5
#define GPIO_C5_PORT                 PORTCbits.RC5
#define GPIO_C5_WPU                  WPUCbits.WPUC5
#define GPIO_C5_OD                   ODCONCbits.ODCC5
#define GPIO_C5_ANS                  ANSELCbits.ANSELC5
#define GPIO_C5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define GPIO_C5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define GPIO_C5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define GPIO_C5_GetValue()           PORTCbits.RC5
#define GPIO_C5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define GPIO_C5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define GPIO_C5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define GPIO_C5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define GPIO_C5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define GPIO_C5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define GPIO_C5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define GPIO_C5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/