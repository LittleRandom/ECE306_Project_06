#include "macros.h"
#include <string.h>
#include "functions.h"
#include "msp430.h"
#include "msp430fr2355.h"

extern char display_line[4][11];
extern char *display[4];
extern int display_code;
extern volatile unsigned long int Time_Sequence;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int counter;

void LCD_intro(void){
  if(counter<1250){
    Time_Sequence = 0;
  }
  
  int check_counter;
  
  if(counter > 200) check_counter = 0;
  if(counter > 500) check_counter = 1;
  if(counter > 800) check_counter = 2;
  if(counter > 1200) check_counter = 3;
  if(counter > 1250) check_counter = 4;
  
  switch(check_counter){

 
  case 0:
  strcpy(display_line[DISPLAY_LINE_0], "   What   ");
  update_string(display_line[DISPLAY_LINE_0], LCD_LINE_0);
    
  strcpy(display_line[DISPLAY_LINE_1], "   is     ");
  update_string(display_line[DISPLAY_LINE_1], LCD_LINE_1);
  
  strcpy(display_line[DISPLAY_LINE_2], "   my     ");
  update_string(display_line[DISPLAY_LINE_2], LCD_LINE_2);
  
  strcpy(display_line[DISPLAY_LINE_3], " purpose? ");
  update_string(display_line[DISPLAY_LINE_3], LCD_LINE_3);
  break;
  
  
  case 1:
  strcpy(display_line[DISPLAY_LINE_0], "   You    ");
  update_string(display_line[DISPLAY_LINE_0], LCD_LINE_0);
  
  strcpy(display_line[DISPLAY_LINE_1], "   go     ");
  update_string(display_line[DISPLAY_LINE_1], LCD_LINE_1);
  
  strcpy(display_line[DISPLAY_LINE_2], "   in     ");
  update_string(display_line[DISPLAY_LINE_2], LCD_LINE_2);
  
  strcpy(display_line[DISPLAY_LINE_3], "  circles.");
  update_string(display_line[DISPLAY_LINE_3], LCD_LINE_3);
  break;
  
  
  
  case 2:
  strcpy(display_line[DISPLAY_LINE_0], "    Oh    ");
  update_string(display_line[DISPLAY_LINE_0], LCD_LINE_0);
  
  strcpy(display_line[DISPLAY_LINE_1], "    My    ");
  update_string(display_line[DISPLAY_LINE_1], LCD_LINE_1);
  
  strcpy(display_line[DISPLAY_LINE_2], "    God.  ");
  update_string(display_line[DISPLAY_LINE_2], LCD_LINE_2);
  
  strcpy(display_line[DISPLAY_LINE_3], "          ");
  update_string(display_line[DISPLAY_LINE_3], LCD_LINE_3);
  break;
  
  case 3:
  strcpy(display_line[DISPLAY_LINE_0], "          ");
  update_string(display_line[DISPLAY_LINE_0], LCD_LINE_0);
  
  strcpy(display_line[DISPLAY_LINE_1], "          ");
  update_string(display_line[DISPLAY_LINE_1], LCD_LINE_1);
  
  strcpy(display_line[DISPLAY_LINE_2], "          ");
  update_string(display_line[DISPLAY_LINE_2], LCD_LINE_2);
  
  strcpy(display_line[DISPLAY_LINE_3], "          ");
  update_string(display_line[DISPLAY_LINE_3], LCD_LINE_3);
  
  break;
  
  case 4:
    break;
  
  }
  
  
}