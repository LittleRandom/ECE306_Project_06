#include "macros.h"
#include "functions.h"
#include "msp430.h"
#include "msp430fr2355.h"


int ADC_Channel = RESET;
volatile int ADC_Thumb = RESET;
volatile int ADC_Left_Detect = RESET;
volatile int ADC_Right_Detect = RESET;

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
  switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
  case ADCIV_NONE:
    break;
  case ADCIV_ADCOVIFG: // When a conversion result is written to the ADCMEM0
    // before its previous conversion result was read.
    break;
  case ADCIV_ADCTOVIFG:                          // ADC conversion-time overflow
    break;
  case ADCIV_ADCHIIFG:                           // Window comparator interrupt flags
    break;
  case ADCIV_ADCLOIFG:                           // Window comparator interrupt flag
    break;
  case ADCIV_ADCINIFG:                           // Window comparator interrupt flag
    break;
    
  case ADCIV_ADCIFG: // ADCMEM0 memory register with the conversion result
    
    ADCCTL0 &= ~ADCENC; // Disable ENC bit.
    
    switch (ADC_Channel++){
    case THUMB: // Channel A2 Interrupt
      ADCMCTL0 &= ~ADCINCH_2; // enabled Last channel A2
      ADC_Left_Detect = ADCMEM0 >> DIVIDE4; // Move result into Global
      ADCMCTL0 |= ADCINCH_3; // Enable Next channel A3
      ADCCTL0 |= ADCSC; // Start next sample
      break;
    case LEFT_IR_DETECT: // Channel A2 Interrupt
      ADCMCTL0 &= ~ADCINCH_3; // Enable Next channel A3
      ADC_Right_Detect = ADCMEM0 >> DIVIDE4; // Move result into Global
      ADCMCTL0 |= ADCINCH_5; // Enable Next channel A5
      ADCCTL0 |= ADCSC; // Start next sample
      break;
    case RIGHT_IR_DETECT:
      ADCMCTL0 &= ~ADCINCH_5;
      ADC_Thumb = ADCMEM0 >> DIVIDE4; // Channel A5
      ADCMCTL0 |= ADCINCH_2;
      ADCCTL0 |= ADCSC; // Start next sample
      break;
    case RESETADC:
      ADC_Channel=RESET;
    default:
      break;
    }
    
    ADCCTL0 |= ADCENC; // Enable Conversions
    
  default:
    break;
  }
}


