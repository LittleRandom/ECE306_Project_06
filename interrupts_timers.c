#include "msp430.h"
#include "msp430fr2355.h"
#include "macros.h"
#include "functions.h"
#include <string.h>

extern volatile unsigned char update_display;

extern volatile unsigned char display_changed;
volatile unsigned long int display_counter= RESET;
volatile unsigned int counter=ONE + TEN_MS;
volatile unsigned int blackline_counter = RESET;
unsigned int debounce_count = RESET;
volatile unsigned int debounce_counter_SW1 = ONE;
volatile unsigned int debounce_counter_SW2 = RESET;
volatile unsigned int pulse = RESET;
volatile unsigned int ready_to_move_counter = RESET;
volatile unsigned int follow_counter = RESET;
volatile unsigned int clock = RESET;


#pragma vector = TIMERB0_CCR0_VECTOR
__interrupt void TimerB0_0_ISR(void){
  // ----------------------------------------------------
  // TimerB0 0 Interrupt handle.
  // ----------------------------------------------------             
  //...... Add What you need happen in the interrupt ......
  TB0CCR0 += TB0CCR0_INTERVAL;                  // Add Offset to TBCCR0
  display_counter++;
  counter ++;
  pulse ++;
  blackline_counter++;
  ready_to_move_counter++;
  follow_counter ++;
  clock++;
}
//

#pragma vector = TIMERB0_CCR1_VECTOR
__interrupt void TIMERB0_1_ISR(void){
  
  // ----------------------------------------------------             
  // TimerB0 1 2, Overflow Interrupt Vector (TBIV ) handler
  // ----------------------------------------------------             
  
  switch(__even_in_range(TB0IV,CCR_RESET)){
  case RESET: break;                              // No interrupt
  case CCR1:                                     // CCR1 not used
    //...... Add What you need happen in the interrupt ......
    
    debounce_counter_SW1++;
    debounce_counter_SW2++;
    if(debounce_counter_SW1 > ONE){
      P4IE |= SW1;
      Red_LED_off();
    }
    if(debounce_counter_SW2 > ONE){
      P2IE |= SW2;
      Grn_LED_off(); 
    }
    TB0CCR1 += TB0CCR1_INTERVAL;             // Add Offset to TBCCR1
    break;
  case CCR2:                                     // CCR2 not used
    //...... Add What you need happen in the interrupt ......
    
    
    TB0CCR2 += TB0CCR2_INTERVAL;      // Add Offset to TBCCR2
    break;
  case CCR_RESET:                                    // overflow
    //...... Add What you need happen in the interrupt ......
    break;
  default: break;
  }
}


