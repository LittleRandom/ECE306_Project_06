#include "msp430.h"
#include "msp430fr2355.h"
#include "macros.h"
#include "functions.h"


extern volatile int ADC_Left_Detect;
extern volatile int ADC_Right_Detect;
extern volatile unsigned int pulse;
extern volatile unsigned int counter;
extern volatile unsigned int blackline_counter;
int on_blackline = RESET;
int blackline_position = RESET;
int car_position;
extern volatile unsigned int ready_to_move_counter;

int follow_Flag = FALSE;
extern int switch_toggle;
extern int movement_states;
extern int following_state;


int check_BlackLine(void){
  
  if((ADC_Left_Detect > LEFT_THRESH)&&(ADC_Right_Detect > RIGHT_THRESH)) return BOTH;
  else if((ADC_Left_Detect > LEFT_THRESH)&&(ADC_Right_Detect < RIGHT_THRESH)) return LB_RW;
  else if((ADC_Left_Detect < LEFT_THRESH)&&(ADC_Right_Detect > RIGHT_THRESH)) return LW_RB;
  else return OFF;
  
}

void position_BlackLine(void){
  
  switch(blackline_position){
  case OFF:
    move_clockwise_slowly();
    blackline_position = check_BlackLine();
    break;
  case LW_RB:
    if((blackline_counter>HALF)&&(blackline_counter< ONE + HALF)){
      car_position = LW_RB;
      blackline_position = DONE;
    } else {
      stop_car();
      blackline_counter = RESET;
      blackline_position = CHECK;
    }
    break;
  case LB_RW:
    if((blackline_counter>HALF)&&(blackline_counter< ONE + HALF)){
      car_position = LB_RW;
      blackline_position = DONE;
    } else {
      stop_car();
      blackline_counter = RESET;
      blackline_position = CHECK;
    }
    break;
  case BOTH:
    move_clockwise_slowly();
    blackline_position = check_BlackLine();
    break;
  case CHECK:
    if(blackline_counter > ONE) blackline_position = check_BlackLine();
    break;
  case DONE:
    break;
  }
}

void get_on_blackline(void){
  
  switch(counter){                                  // Flag to turn make care move.
  case HALF:
    switch_toggle = ON;
    break;
  }
  
  /*-------------------------HOLD STATE------------------------------------------*/
  switch(movement_states){
  case HOLD:                                       // Do nothing
    if(switch_toggle) movement_states = MOVE;      // Until flag is set.
    switch_toggle = RESET;
    break;
  case MOVE:
    switch_toggle = RESET;
    car_forward_slow();
    if(check_BlackLine()){
      stop_car();
      counter = RESET;
      switch_toggle = ON;
    }
    if(switch_toggle){
      movement_states = BLACKLINE;
      counter = RESET;
    }
    break;
/*-------------------------FIND BLACK LINE------------------------------------------*/

  case BLACKLINE:
    if(blackline_position == DONE){
      movement_states = ON_BLACKLINE;
      ready_to_move_counter= RESET;
    }
    if(counter > TWO){          // black line detection after 2 seconds
      position_BlackLine();
    } else if (counter > ONE) { // will turn no matter what for a second
      move_clockwise_slowly();
    } else {
      stop_car(); // pauses for about a second before doing anything
    }
    
    break;
    
  /*-------------------------ON THE BLACK LINE------------------------------------------*/
    
  case ON_BLACKLINE:
    stop_car();
    if(ready_to_move_counter > ONE) movement_states = FOLLOW_BLACKLINE;
    break;
  case FOLLOW_BLACKLINE:
    follow_BlackLine();
    follow_Flag = TRUE;
    if(following_state == FOLLOW_DONE) movement_states = FOLLOW_DONE;
    break;
  case FOLLOW_DONE:
    follow_BlackLine();
    if(following_state == PROJECT_7_FINISHED) movement_states = PROJECT_7_FINISHED;
    break;
  case PROJECT_7_FINISHED:
    stop_car();
    break;
  }
}