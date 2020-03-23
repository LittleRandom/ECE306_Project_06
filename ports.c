//------------------------------------------------------------------------------
//  File Name: ports.c
//
//  Description: Contains conditions and assignments for Ports on MSP - 430
//
//
//  Quoc Chuong Vu
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.12.4)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "macros.h"
#include  "msp430.h"
#include  "functions.h"

void Init_Port1(void){
  
  P1DIR = 0xFF;
  P1OUT = 0x00;
  
  //Pin 0
  P1SEL0 &= ~RED_LED;       // LED output
  P1SEL1 &= ~RED_LED;       // LED output
  P1DIR  |=  RED_LED;       // Direction = in
  P1OUT  &= ~RED_LED;
  
  
  //Pin 1
  P1SEL0 |= A1_SEEED;       // Receives power
  P1SEL1 |= A1_SEEED;       // Receives power
  
  //Pin 2
  P1SEL0 |= V_DETECT_L;     // Voltage Detect Left , B0 SDA
  P1SEL1 |= V_DETECT_L;     // Voltage Detect Left , B0 SDA
  
  //Pin 3
  P1SEL0 |= V_DETECT_R;     // Voltage Detect Right, B0 SCL
  P1SEL1 |= V_DETECT_R;     // Voltage Detect Right, B0 SCL
  
  //Pin 4
  P1SEL0 |= A4_SEEED;       // SEEED  , Analog In
  P1SEL1 |= A4_SEEED;       // SEEED  , Analog In 
  
  //Pin 5
  P1SEL0 |= V_THUMB;        // Thumb Voltage, Analog_IN
  P1SEL1 |= V_THUMB;        // Thumg Voltage, Analog_IN
  
  //Pin 6
  P1SEL0 |= LFXOUT;         // LP_UART_RX
  P1SEL1 &= ~LFXOUT;        // LP_UART_RX
  
  //Pin 7
  P1SEL0 |= LFXIN;          // LP_UART_TX
  P1SEL1 &= ~LFXIN;         // LP_UART_TX
  
}

void Init_Port2(void){
  
  P2DIR = 0xFF;             // Set P1 direction to output
  P2OUT = 0x00;             // P1 set Low
  
  //Pin 0
  P2SEL0 &= ~P2_0;          // P2_0 GPIO operation
  P2SEL1 &= ~P2_0;          // P2_0 GPIO operation
  P2DIR  &= ~P2_0;          // Direction = input
  
  //Pin 1
  P2SEL0 &= ~P2_1;          // P2_1 GPIO operation
  P2SEL1 &= ~P2_1;          // P2_1 GPIO operation
  P2DIR  &= ~P2_1;          // Direction = input
  
  //Pin 2
  P2SEL0 &= ~P2_2;          // P2_2 GPIO operation
  P2SEL1 &= ~P2_2;          // P2_2 GPIO operation
  P2DIR  &= ~P2_2;          // Direction = input
  
  //Pin 3
  P2SEL0 &= ~SW2;           // SW2 Operation
  P2SEL1 &= ~SW2;           // SW2 Operation
  P2DIR  &= ~SW2;           // Direction = input
  P2OUT  |= SW2;            // Configure pullup resistor
  P2REN  |= SW2;            // Enable pullup resistor
  
  P2IES |= SW2;          // P2.0 Hi/Lo edge interrupt
  P2IFG &= ~SW2;         // Clear all P2.6 interrupt flags
  P2IE |= SW2;           // P2.6 interrupt enabled
  
  //Pin 4
  P2SEL0 &= ~P2_4;          // P2_4 GPIO operation
  P2SEL1 &= ~P2_4;          // P2_4 GPIO operation
  P2DIR  &= ~P2_4;          // Direction = input
  
  //Pin 5
  P2SEL0 &= ~P2_5;          // P2_5 GPIO operation
  P2SEL1 &= ~P2_5;          // P2_5 GPIO operation
  P2DIR  &= ~P2_5;          // Direction = input
  
  //Pin 6
  P2SEL0 &= ~LFXOUT;        // LFXOUT Clock operation
  P2SEL1 |= LFXOUT;         // LFXOUT Clock operation
  
  //Pin 7
  P2SEL0 &= ~LFXIN;         // LFXIN Clock operation
  P2SEL1 |= LFXIN;          // LFXIN Clock operation
  
}

void Init_Port3(int port3_4){
  
  P3DIR = 0xFF;             // Set P1 direction to output
  P3OUT = 0x00;             // P1 set Low
  
  //Pin 0
  P3SEL0 &= ~TEST_PROB;     // TEST_PROBE GPIO
  P3SEL1 &= ~TEST_PROB;     // TEST_PROBE GPIO
  P3DIR  &= ~TEST_PROB;     // Direction: Input
  
  //Pin 1
  P3SEL0 |= CHECK_BAT;      // Checks battery
  P3SEL1 |= CHECK_BAT;      // Checks battery
  
  //Pin 2
  P3SEL0 |= OA2N;           // PhotoDiode Circuit
  P3SEL1 |= OA2N;           // PhotoDiode Circuit
  
  //Pin 3
  P3SEL0 |= OA2P;           // PhotoDiode Circuit
  P3SEL1 |= OA2P;           // PhotoDiode Circuit
  
  //Pin 4
  if(port3_4){              // if Port 3.4 is true its SMLCK, false is GPIO 
    P3SEL0 |= SMCLK_OUT;    // SMCLK
    P3SEL1 &= ~ SMCLK_OUT;  // SMCLK
    P3DIR  |= SMCLK_OUT;    // Clock needs output
  } else {
    P3SEL0 &= ~SMCLK_OUT;   // GPIO
    P3SEL1 &= ~SMCLK_OUT;   // GPIO
    P3DIR  &= ~SMCLK_OUT;   // GPIO in
  }
  
  //Pin 5
  P3SEL0 &= ~IR_LED;        // Infrared LED GPIO
  P3SEL1 &= ~IR_LED;        // Infrared LED GPIO
  P3DIR  |=  IR_LED;        // Direction : Output
  P3OUT  &= ~IR_LED;        // OFF
  
  //Pin 6
  P3SEL0 &= ~IOT_LINK;      // Analog_out GPIO
  P3SEL1 &= ~IOT_LINK;      // Analog_out GPIO
  P3DIR  &= ~IOT_LINK;      // Direction: Input
  
  //Pin 7
  P3SEL0 &= ~P3_7;          // Function not specified TF GPIO
  P3SEL1 &= ~P3_7;          // Function not specified TF GPIO
  P3DIR  &= ~P3_7;          // Direction : Input
  
}

void Init_Port4(void){
  // Configure PORT 4
  
  P4DIR = 0xFF;             // Set P1 direction to oitput
  P4OUT = 0x00;             // P1 set Low
  
  P4SEL0 &= ~RESET_LCD;     // RESET_LCD GPIO operation
  P4SEL1 &= ~RESET_LCD;     // RESET_LCD GPIO operation
  P4DIR  |= RESET_LCD;      // Set RESET_LCD direction to output
  P4OUT  |= RESET_LCD;      // Set RESET_LCD Off [High]
  
  P4SEL0 &= ~SW1;           // SW1 GPIO operation
  P4SEL1 &= ~SW1;           // SW1 GPIO operation
  P4DIR  &= ~SW1;           // Direction = input
  P4OUT  |= SW1;            // Configure pullup resistor
  P4REN  |= SW1;            // Enable pullup resistor
  
  P4IES |= SW1;          // P2.0 Hi/Lo edge interrupt
  P4IFG &= ~SW1;         // Clear all P2.6 interrupt flags
  P4IE |= SW1;           // P2.6 interrupt enabled
  
  P4SEL0 |= UCA1TXD;        // USCI_A1 UART operation
  P4SEL1 &= ~UCA1TXD;       // USCI_A1 UART operation
  P4SEL0 |= UCA1RXD;        // USCI_A1 UART operation
  P4SEL1 &= ~UCA1RXD;       // USCI_A1 UART operation
  
  P4SEL0 &= ~UCB1_CS_LCD;   // UCB1_CS_LCD GPIO operation
  P4SEL1 &= ~UCB1_CS_LCD;   // UCB1_CS_LCD GPIO operation
  P4DIR  |= UCB1_CS_LCD;    // Set SPI_CS_LCD direction to output
  P4OUT  |= UCB1_CS_LCD;    // Set SPI_CS_LCD Off [High]
  
  P4SEL0 |= UCB1CLK;        // UCB1CLK SPI BUS operation
  P4SEL1 &= ~UCB1CLK;       // UCB1CLK SPI BUS operation
  
  P4SEL0 |= UCB1SIMO;       // UCB1SIMO SPI BUS operation
  P4SEL1 &= ~UCB1SIMO;      // UCB1SIMO SPI BUS operation
  
  P4SEL0 |= UCB1SOMI;       // UCB1SOMI SPI BUS operation
  P4SEL1 &= ~UCB1SOMI;      // UCB1SOMI SPI BUS operation
}

void Init_Port5(void){
  
  P5DIR = 0xFF;             // Set P1 direction to oitput
  P5OUT = 0x00;             // P1 set Low
  
  //Pin 0
  P5SEL0 |= IOT_RESET;      // Function to reset IOT, ADC
  P5SEL1 |= IOT_RESET;      // Function to reset IOT, ADC
  
  //Pin 1
  P5SEL0 |= V_BAT;          // Function for Voltage Battery, ADC
  P5SEL1 |= V_BAT;          // Function for Voltage Battery, ADC
  
  //Pin 2
  P5SEL0 |= IOT_PROG_SEL;   // Function, ADC
  P5SEL1 |= IOT_PROG_SEL;   // Function, ADC
  
  //Pin 3
  P5SEL0 |= V_3_3;          // Function 3.3v, ADC
  P5SEL1 |= V_3_3;          // Function 3.3v, ADC
  
  //Pin 4
  P5SEL0 &= ~IOT_PROG_MODE; // GP I/O
  P5SEL1 &= ~IOT_PROG_MODE; // GP I/O
  P5DIR  &= ~IOT_PROG_MODE; // Direction: Output
}

void Init_Port6(void){
  
  P6DIR = 0xFF;             // Set P1 direction to oitput
  P6OUT = 0x00;             // P1 set Low
  
  //Pin 0
  P6SEL0 |=  R_FORWARD;     // Right motor forward
  P6SEL1 &= ~R_FORWARD;     // Right motor forward
  P6DIR  |=  R_FORWARD;     // Direction: out
  
  //Pin 1
  P6SEL0 |=  L_FORWARD;     // Left Motor forward
  P6SEL1 &= ~L_FORWARD;     // Left Motor forward
  P6DIR  |=  L_FORWARD;     // Direction: out
  
  //Pin 2
  P6SEL0 |=  R_REVERSE;     // Right Motor Reverse
  P6SEL1 &= ~R_REVERSE;     // Right Motor Reverse
  P6DIR  |=  R_REVERSE;     // Direction: out
  
  //Pin 3
  P6SEL0 |=  L_REVERSE;     // Left Motor Reverse
  P6SEL1 &= ~L_REVERSE;     // Left Motor Reverse
  P6DIR  |=  L_REVERSE;     // Direction: out

  
  //Pin 4
  P6SEL0 &= ~LCD_BACKLITE;  // LCD Back Light control
  P6SEL1 &= ~LCD_BACKLITE;  // LCD Back Light control
  P6DIR  |=  LCD_BACKLITE;  // Direction: out
  P6OUT  |=  LCD_BACKLITE;
  
  //Pin 5
  P6SEL0 &= ~P6_5;          // GP I/O
  P6SEL1 &= ~P6_5;          // GP I/O
  P6DIR  &= ~P6_5;          // Direction: out
  
  //Pin 6
  P6SEL0 &= ~GRN_LED;       // Control for Green LED
  P6SEL1 &= ~GRN_LED;       // Control for Green LED 
  P6DIR  |=  GRN_LED;       // Direction: out
  P6OUT  &= ~GRN_LED;
  
}