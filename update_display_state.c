#include "macros.h"
#include <string.h>
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

extern char display_line[NUM_OF_LINES][NUM_OF_CHARS];
extern char *display[NUM_OF_LINES];
extern volatile int display_code;
extern volatile unsigned long int display_counter;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern unsigned int debounce_count;
extern char display_thumb[NUM_OF_CHARS];
extern char display_IR_reading_R[NUM_OF_CHARS];
extern char display_IR_reading_L[NUM_OF_CHARS];
extern int movement_states;
extern volatile unsigned int clock;

int switch_toggle=RESET;
int movement_states=RESET;
extern int following_state;


extern int car_position;
extern int IR_LED_ONOFF;

char T_thousands;
char T_hundreds;
char T_tens;
char T_ones;

char R_thousands;
char R_hundreds;
char R_tens;
char R_ones;

char L_thousands;
char L_hundreds;
char L_tens;
char L_ones;

extern char one_sec;
extern char ten_sec;
extern char hun_sec;
extern char hun_milli_sec;

void update_display_state(void){
  
  convert_ADC();
  
  if(IR_LED_ONOFF){
    display_thumb[CHAR3] = 'O';
    display_thumb[CHAR2] = ':';
    display_thumb[CHAR1] = 'R';
    display_thumb[CHAR0] = 'I';
  } else {
    display_thumb[CHAR5] = ' ';
    display_thumb[CHAR4] = ' ';
    display_thumb[CHAR3] = 'X';
    display_thumb[CHAR2] = ':';
    display_thumb[CHAR1] = 'R';
    display_thumb[CHAR0] = 'I';
  }
  
  display_IR_reading_L[CHAR10] = RESET;
  display_IR_reading_L[CHAR9] = L_ones;
  display_IR_reading_L[CHAR8] = L_tens;
  display_IR_reading_L[CHAR7] = L_hundreds;
  display_IR_reading_L[CHAR6] = 'L';  
  display_IR_reading_L[CHAR5] = ' ';
  display_IR_reading_L[CHAR4] = ' ';
  display_IR_reading_L[CHAR3] = R_ones;
  display_IR_reading_L[CHAR2] = R_tens;
  display_IR_reading_L[CHAR1] = R_hundreds;
  display_IR_reading_L[CHAR0] = 'R';
  
  display_thumb[CHAR10] = RESET;
  display_thumb[CHAR9] = T_ones;
  display_thumb[CHAR8] = T_tens;
  display_thumb[CHAR7] = T_hundreds;
  display_thumb[CHAR6] = T_thousands;  
  display_thumb[CHAR5] = ' ';
  display_thumb[CHAR4] = ' ';
  
  display_IR_reading_R[CHAR10] = RESET;
  display_IR_reading_R[CHAR9] = hun_milli_sec;
  display_IR_reading_R[CHAR8] = '.';
  display_IR_reading_R[CHAR7] = one_sec;
  display_IR_reading_R[CHAR6] = ten_sec;  
  display_IR_reading_R[CHAR5] = hun_sec;
  display_IR_reading_R[CHAR4] = '=';
  display_IR_reading_R[CHAR3] = 'E';
  display_IR_reading_R[CHAR2] = 'M';
  display_IR_reading_R[CHAR1] = 'I';
  display_IR_reading_R[CHAR0] = 'T';
  
  update_string(display_IR_reading_R, LCD_LINE_3);
  
  update_string(display_thumb, LCD_LINE_1);
  
  update_string(display_IR_reading_L, LCD_LINE_2);
  
  switch(movement_states){
  case HOLD:
    update_string( "   HOLD   ", LCD_LINE_0);
    break;
  case MOVE:
    update_string("    GO    ", LCD_LINE_0);
    break;
  case BLACKLINE:
    update_string("BLACKLINE ", LCD_LINE_0);
    break;
  case ON_BLACKLINE:
    update_string("POSITIONED", LCD_LINE_0);
    break;
  case FOLLOW_BLACKLINE:
    if(car_position == LB_RW){     
      update_string("LBLK RWHT ", LCD_LINE_0);
    } else if(car_position == LW_RB){
      update_string("LWHT RBLK ", LCD_LINE_0);
    } else {
      update_string("  NEITHER ", LCD_LINE_0);
    }
    break;
  case FOLLOW_DONE:
    switch(following_state){
    case TURN_90:
      update_string("TURNING 90", LCD_LINE_0);
      break;     
    case MOVE_TO_MIDDLE:
      update_string("MOVE2MIDDL", LCD_LINE_0);
      break;
    }
    break;
  case PROJECT_7_FINISHED:
      update_string("PROJ7FIN. ", LCD_LINE_0);
    break;
  }
  
  switch(display_counter){
  case HUNDRED_MS:
    display_counter = RESET;
    break;
  case RESET:
    update_display = CHANGE_DISPLAY_ON ;
    display_changed = CHANGE_DISPLAY_ON;
    break;
  }
  
  
}

