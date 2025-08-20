/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
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

#include "../pins.h"


void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATC = 0x3;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONC = 0x3;

    /**
    TRISx registers
    */
    TRISA = 0x1A;
    TRISC = 0xC;

    /**
    ANSELx registers
    */
    ANSELA = 0x0;
    ANSELC = 0xC;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUC = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONC = 0x3F;

    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLC = 0x3F;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RC0I2C = 0x1;
    RC1I2C = 0x1;
    /**
    PPS registers
    */
    U1RXPPS = 0x4; //RA4->UART1:RX1;
    RA5PPS = 0x10;  //RA5->UART1:TX1;
    I2C1SCLPPS = 0x10;  //RC0->I2C1:SCL1;
    RC0PPS = 0x21;  //RC0->I2C1:SCL1;
    I2C1SDAPPS = 0x11;  //RC1->I2C1:SDA1;
    RC1PPS = 0x22;  //RC1->I2C1:SDA1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;


}
  
void PIN_MANAGER_IOC(void)
{
}
/**
 End of File
*/