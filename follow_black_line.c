#include "msp430.h"
#include "msp430fr2355.h"
#include "macros.h"
#include "functions.h"

extern volatile int ADC_Left_Detect;
extern volatile int ADC_Right_Detect;
extern volatile unsigned int pulse;
extern volatile unsigned int counter;
extern volatile unsigned int blackline_counter;
extern int on_blackline;
extern int blackline_position;
extern int car_position;
extern volatile unsigned int ready_to_move_counter;

extern int switch_toggle;
extern int movement_states;

extern int follow_Flag;
int following_state;
int previous_follow_state = RESET;

int turn_90_state = RESET;

extern volatile unsigned int follow_counter;


void follow_BlackLine(void){
  
  switch(following_state){
    
    
    /* ------------------------------HOLDING STATE---------------------------------------- */
    
    
  case FOLLOW_HOLD:
    if(follow_Flag){
      car_forward_medium();
      follow_counter = RESET;
      following_state = FOLLOW_START;
    }
    counter = RESET;
    break;
    
    
    /* -------------------------------STARTING STATE---------------------------------------- */
    
    
  case FOLLOW_START:                            // CHECKING WHERE THE CAR IS
    switch(check_BlackLine()){
    case LB_RW:                                 // CAR IS ON LEFT BLACK RIGHT WHITE
      previous_follow_state = LB_RW;
      break;
    case LW_RB:                                 // CAR IS ON LEFT WHITE RIGHT BLACK
      previous_follow_state = LW_RB;
      break;
    case BOTH:                                  // CAR IS CURRENTLY ON BLACK LINE
      previous_follow_state = BOTH;
      break;
    case OFF:                                   // CAR IS CURRENTLY OFF THE BLACK LINE
      previous_follow_state = OFF;
      break;
    }
    if(car_position==LB_RW) following_state = FOLLOW_CORRECT_LB_RW;
    else if(car_position==LW_RB) following_state= FOLLOW_CORRECT_LW_RB;
    break;
    
    
    /* ------------------------------- LEFT BLACK RIGHT WHITE ----------------------------- */
    
    
  case FOLLOW_CORRECT_LB_RW:                    // CORRECTION OF THE MISTAKE IF FOLLOWING LB RW
    switch(check_BlackLine()){
    case LB_RW:
      car_forward_fast();
      break;
    case LW_RB:
      move_clockwise_follow();
      break;
    case BOTH:
      switch(previous_follow_state){
      case LB_RW:
        move_clockwise_follow();
        break;
      case LW_RB:
        move_clockwise_follow();
        break;
      case BOTH:
        move_clockwise_follow();
        break;
      case OFF:
        break;
      }
      break;
    case OFF:
      switch(previous_follow_state){
      case LB_RW:
        move_counterclockwise_follow();
        break;
      case LW_RB:
        move_clockwise_follow();
        break;
      case BOTH:
        car_forward_fast();
        break;
      case OFF:
        move_counterclockwise_follow();
        break;
      }
      break;
    }
    following_state = FOLLOW_START;
    break;
    
    
    /*----------------------------------LEFT WHITE RIGHT BLACK -------------------------------------- */
    
    
  case FOLLOW_CORRECT_LW_RB:                    // CORRECTION IF LW RB
    switch(check_BlackLine()){
    case LB_RW:
      move_counterclockwise_follow();
      break;
    case LW_RB:
      car_forward_fast();
      break;
    case BOTH:
      switch(previous_follow_state){
      case LB_RW:
        move_counterclockwise_follow();
        break;
      case LW_RB:
        move_counterclockwise_follow();
        break;
      case BOTH:
        move_counterclockwise_follow();
        break;
      case OFF:
        break;
      }
      break;
    case OFF:
      switch(previous_follow_state){
      case LB_RW:
        move_counterclockwise_follow();
        break;
      case LW_RB:
        move_clockwise_follow();
        break;
      case BOTH:
        move_counterclockwise_follow();
        break;
      case OFF:
        move_clockwise_follow();
        break;
      }
      break;
    }
    if(counter < CIRCLE_2) following_state = FOLLOW_START;
    else following_state = FOLLOW_DONE;
    
    break;
    /* --------------------------------------DONE WITH THE CIRCLE --------------------------------- */
  case FOLLOW_DONE:
    stop_car();
    counter = RESET;
    following_state = TURN_90;
    break;
  case TURN_90:
    counter = RESET;
    following_state = TURN_90_FINISHED;
    RIGHT_FORWARD_SPEED = STOP;
    LEFT_FORWARD_SPEED = LEFT_MEDIUM;
    RIGHT_REVERSE_SPEED = RIGHT_MEDIUM;
    LEFT_REVERSE_SPEED = STOP;
    break;
  case TURN_90_FINISHED:
    if(counter> TURN90_TIME){
      car_forward_fast();
      counter = RESET;
      following_state = MOVE_TO_MIDDLE;
    }
    break;
  case MOVE_TO_MIDDLE:
  if(counter > MOVE_TO_CENTER_TIME){
    stop_car();
    following_state = PROJECT_7_FINISHED;
  }
  break;
  case PROJECT_7_FINISHED:
    break;
  }
}

