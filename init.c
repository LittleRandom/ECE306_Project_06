//------------------------------------------------------------------------------
//  File Name: init.c
//
//  Description: Contains the conditions to reset and display on the LCD
//
//
//  Quoc Chuong Vu
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.12.4)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "macros.h"
#include  "functions.h"
#include "msp430.h"
#include "msp430fr2355.h"

extern char display_line[NUM_LINE][DISPLAY_NUM_INDEX];
extern volatile unsigned char update_display;
extern char *display[NUM_LINE];
extern volatile unsigned int update_display_count;
extern unsigned int port3_4;

void Init_All(void){
  
  PM5CTL0 &= ~LOCKLPM5;
  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers
  Init_LCD();                          // Initialize LCD
  Init_LEDs();                         // Initialize LED
  Init_ADC();                          // Initialize ADC
  
}

void Init_Ports(void){// This function calls the rest of the initialization functions
  
  Init_Port1();
  Init_Port2();
  Init_Port3(USE_GPIO);
  Init_Port4();
  Init_Port5();
  Init_Port6();
  
}

// Initializes the LCD to the current stored data
void Init_Conditions(void){
  //------------------------------------------------------------------------------
  int i;
  
  for(i=DISPLAY_ZERO_INDEX;i<DISPLAY_NUM_INDEX;i++){
    display_line[DISPLAY_LINE_0][i] = RESET_STATE;
    display_line[DISPLAY_LINE_1][i] = RESET_STATE;
    display_line[DISPLAY_LINE_2][i] = RESET_STATE;
    display_line[DISPLAY_LINE_3][i] = RESET_STATE;
  }
  display_line[DISPLAY_LINE_0][DISPLAY_POSITION_END] = DISPLAY_CHAR_BLANK;
  display_line[DISPLAY_LINE_1][DISPLAY_POSITION_END] = DISPLAY_CHAR_BLANK;
  display_line[DISPLAY_LINE_2][DISPLAY_POSITION_END] = DISPLAY_CHAR_BLANK;
  display_line[DISPLAY_LINE_3][DISPLAY_POSITION_END] = DISPLAY_CHAR_BLANK;
  
  display[DISPLAY_LINE_0] = &display_line[DISPLAY_LINE_0][DISPLAY_POSITION_FRONT];
  display[DISPLAY_LINE_1] = &display_line[DISPLAY_LINE_1][DISPLAY_POSITION_FRONT];
  display[DISPLAY_LINE_2] = &display_line[DISPLAY_LINE_2][DISPLAY_POSITION_FRONT];
  display[DISPLAY_LINE_3] = &display_line[DISPLAY_LINE_3][DISPLAY_POSITION_FRONT];
  update_display = UPDATE_DISPLAY_FALSE;
  update_display_count = DISPLAY_COUNT_START;
  // Interrupts are disabled by default, enable them.
  enable_interrupts();
  //------------------------------------------------------------------------------
}

void Init_Timers(void){
  Init_Timer_B0();
  Init_Timer_B3();
}

void Init_ADC(void){
  
  // ADCCTL0 Register
  ADCCTL0 = RESET; // Reset
  ADCCTL0 |= ADCSHT_2; // 16 ADC clocks
  ADCCTL0 |= ADCMSC; // MSC
  ADCCTL0 |= ADCON; // ADC ON
  
  // ADCCTL1 Register
  ADCCTL2 = RESET; // Reset
  ADCCTL1 |= ADCSHS_0; // 00b = ADCSC bit
  ADCCTL1 |= ADCSHP; // ADC sample-and-hold SAMPCON signal from sampling timer.
  ADCCTL1 &= ~ADCISSH; // ADC invert signal sample-and-hold.
  ADCCTL1 |= ADCDIV_0; // ADC clock divider - 000b = Divide by 1
  ADCCTL1 |= ADCSSEL_0; // ADC clock MODCLK
  ADCCTL1 |= ADCCONSEQ_0; // ADC conversion sequence 00b = Single-channel single-conversion
  // ADCCTL1 & ADCBUSY identifies a conversion is in process
  
  // ADCCTL2 Register
  ADCCTL2 = RESET; // Reset
  ADCCTL2 |= ADCPDIV0; // ADC pre-divider 00b = Pre-divide by 1
  ADCCTL2 |= ADCRES_2; // ADC resolution 10b = 12 bit (14 clock cycle conversion time)
  ADCCTL2 &= ~ADCDF; // ADC data read-back format 0b = Binary unsigned.
  ADCCTL2 &= ~ADCSR; // ADC sampling rate 0b = ADC buffer supports up to 200 ksps
  
  // ADCMCTL0 Register
  ADCMCTL0 |= ADCSREF_0; // VREF - 000b = {VR+ = AVCC and VR– = AVSS }
  ADCMCTL0 |= ADCINCH_2; // V_THUMB (0x20) Pin 5 A5
  
  ADCIE |= ADCIE0; // Enable ADC conv complete interrupt
  ADCCTL0 |= ADCENC; // ADC enable conversion.
  ADCCTL0 |= ADCSC; // ADC start conversion.
  
}

void Init_Timer_B0(void){
  TB0CTL = TBSSEL__SMCLK;               // SMCLK source
  TB0CTL|= TBCLR ;                      // Resets TB0R , clock divider, count direction
  TB0CTL|= MC__CONTINOUS;               // Continuous up
  
  // Divides the clock speed
  TB0CTL|= ID_1;                        // Divide clock by 2
  TB0EX0= TBIDEX_7;                    // Divide clock by an additional 8
  TB0CCR0= TB0CCR0_INTERVAL;           // CCR0
  TB0CCTL0|= CCIE;                      // CCR0 enable interrupt
  
  //
  TB0CCR1 = TB0CCR1_INTERVAL;        // CCR1
  TB0CCTL1 |= CCIE;                   // CCR1 enable interrupt
  TB0CCR2 = TB0CCR2_INTERVAL;        // CCR2
  TB0CCTL2 |= CCIE;                   // CCR2 enable interrupt
  
  TB0CTL&= ~TBIE ;                      // Disable Overflow Interrupt
  TB0CTL&= ~TBIFG ;                     // Clear Overflow Interrupt flag
}

void Init_Timer_B3(void){
  //------------------------------------------------------------------------------
  // SMCLK source, up count mode, PWM Right Side
  // TB3.1 P6.0 R_FORWARD
  // TB3.2 P6.1 L_FORWARD
  // TB3.3 P6.2 R_REVERSE
  // TB3.4 P6.3 L_REVERSE
  //------------------------------------------------------------------------------
  TB3CTL = TBSSEL__SMCLK; // SMCLK
  TB3CTL |= MC__UP; // Up Mode
  TB3CTL |= TBCLR; // Clear TAR
  TB3CCR0 = WHEEL_PERIOD; // PWM Period
  TB3CCTL1 = OUTMOD_7; // CCR1 reset/set
  RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM duty cycle
  TB3CCTL2 = OUTMOD_7; // CCR2 reset/set
  LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM duty cycle
  TB3CCTL3 = OUTMOD_7; // CCR3 reset/set
  RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM duty cycle
  TB3CCTL4 = OUTMOD_7; // CCR4 reset/set
  LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM duty cycle
  //------------------------------------------------------------------------------
}