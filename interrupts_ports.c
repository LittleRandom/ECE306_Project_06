// Port 4 interrupt. For switches, they are disabled for the duration
// of the debounce timer. Flag is set that user space can check.

#include "msp430.h"
#include "msp430fr2355.h"
#include "macros.h"
#include "functions.h"

int IR_LED_ONOFF = OFF;
int button_on = RESET;
extern unsigned int debounce_count;
extern volatile unsigned int debounce_counter_SW1;
extern volatile unsigned int debounce_counter_SW2;
extern volatile unsigned int counter;

#pragma vector = PORT4_VECTOR
__interrupt void switchP4_interrupt(void){
  // Switch 1
  if (P4IFG & SW1){
    P4IFG &= ~SW1; // IFG SW1 cleared
    debounce_count++;
    debounce_counter_SW1 = RESET;
    P4IE  &= ~SW1;
    Red_LED_on();
    counter = RESET;
    }
  
}

#pragma vector = PORT2_VECTOR
__interrupt void switchP2_interrupt(void){
  // Switch 2
  if (P2IFG & SW2) {
    P2IFG &= ~SW2; // IFG SW2 cleared
    if(IR_LED_ONOFF == ON) {
      toggle_IR_LED(OFF);
      IR_LED_ONOFF = OFF;
    }
    else {
      toggle_IR_LED(ON);
      IR_LED_ONOFF = ON;
    }
    debounce_count++;
    debounce_counter_SW2 = RESET;
    P2IE &= ~SW2;
    Grn_LED_on();
  }
}
