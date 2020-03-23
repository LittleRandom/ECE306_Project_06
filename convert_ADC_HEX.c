#include "macros.h"
#include "functions.h"
#include <string.h>

char display_IR_reading_L[NUM_OF_CHARS];
char display_IR_reading_R[NUM_OF_CHARS];
char display_thumb[NUM_OF_CHARS];

extern char display_line[NUM_OF_LINES][NUM_OF_CHARS];
extern char *display[NUM_OF_LINES];

extern char T_thousands;
extern char T_hundreds;
extern char T_tens;
extern char T_ones;

extern char R_thousands;
extern char R_hundreds;
extern char R_tens;
extern char R_ones;

extern char L_thousands;
extern char L_hundreds;
extern char L_tens;
extern char L_ones;

extern volatile int ADC_Thumb;
extern volatile int ADC_Left_Detect;
extern volatile int ADC_Right_Detect;
extern volatile unsigned int clock;

char one_sec = RESET;
char ten_sec = RESET;
char hun_sec = RESET;
char hun_milli_sec = RESET;

volatile unsigned int Left_Average;
volatile unsigned int Right_Average;

unsigned int right_detect1 = RESET;
unsigned int right_detect2 = RESET;
unsigned int right_detect3 = RESET;
unsigned int right_detect4 = RESET;
unsigned int right_detect5 = RESET;
unsigned int right_detect6 = RESET;
unsigned int right_detect7 = RESET;
unsigned int right_detect8 = RESET;

unsigned int left_detect1 = RESET;
unsigned int left_detect2 = RESET;
unsigned int left_detect3 = RESET;
unsigned int left_detect4 = RESET;
unsigned int left_detect5 = RESET;
unsigned int left_detect6 = RESET;
unsigned int left_detect7 = RESET;
unsigned int left_detect8 = RESET;

void convert_ADC(void){
  HEXtoBCD_left(); // Convert result to Strin
  HEXtoBCD_right();
  HEXtoBCD_thumb(ADC_Thumb);
  HEXtoBCD_Clock(clock);
  
}

void HEXtoBCD_right(void){
  average_right_thresh();
  volatile unsigned int adc_val = Right_Average;
  
  R_thousands = RESET;                                // Reset thousands place
  while(adc_val >= THOUSANDS_PLACE){                      // Count the thousands place
    adc_val -= THOUSANDS_PLACE;                            // decrement thousands place
    R_thousands ++;                               // increment thousands place
  }
  R_thousands += ASCIISHIFT;
  
  R_hundreds = RESET;                                 // Counts hundreds place              
  while(adc_val >= HUNDREDS_PLACE){                        
    adc_val -= HUNDREDS_PLACE;
    R_hundreds ++;
  }
  R_hundreds += ASCIISHIFT;
  
  R_tens = RESET;                                     // Counts tens place
  while(adc_val >= TENS_PLACE){
    adc_val -= TENS_PLACE;
    R_tens ++;
  }
  R_tens += ASCIISHIFT;
  
  R_ones = RESET;                                     // Counts ones place
  while(adc_val >= ONES_PLACE){
    adc_val -= ONES_PLACE;
    R_ones ++;
  }
  R_ones += ASCIISHIFT;
  
}

void HEXtoBCD_left(void){
  average_left_thresh();
  volatile unsigned int adc_val = Left_Average;

  L_thousands = RESET;                                // Reset thousands place
  while(adc_val >= THOUSANDS_PLACE){                      // Count the thousands place
    adc_val -= THOUSANDS_PLACE;                            // decrement thousands place
    L_thousands ++;                               // increment thousands place
  }
  L_thousands += ASCIISHIFT;
  
  L_hundreds = RESET;                                 // Counts hundreds place              
  while(adc_val >= HUNDREDS_PLACE){                        
    adc_val -= HUNDREDS_PLACE;
    L_hundreds ++;
  }
  L_hundreds += ASCIISHIFT;
  
  L_tens = RESET;                                     // Counts tens place
  while(adc_val >= TENS_PLACE){
    adc_val -= TENS_PLACE;
    L_tens ++;
  }
  L_tens += ASCIISHIFT;
  
  L_ones = RESET;                                     // Counts ones place
  while(adc_val >= ONES_PLACE){
    adc_val -= ONES_PLACE;
    L_ones ++;
  }
  L_ones += ASCIISHIFT;
  
  
}

void HEXtoBCD_thumb(int adc_val){
  
  
  T_thousands = RESET;                                // Reset thousands place
  while(adc_val >= THOUSANDS_PLACE){                      // Count the thousands place
    adc_val -= THOUSANDS_PLACE;                            // decrement thousands place
    T_thousands ++;                               // increment thousands place
  }
  T_thousands += ASCIISHIFT;
  
  T_hundreds = RESET;                                 // Counts hundreds place              
  while(adc_val >= HUNDREDS_PLACE){                        
    adc_val -= HUNDREDS_PLACE;
    T_hundreds ++;
  }
  T_hundreds += ASCIISHIFT;
  
  T_tens = RESET;                                     // Counts tens place
  while(adc_val >= TENS_PLACE){
    adc_val -= TENS_PLACE;
    T_tens ++;
  }
  T_tens += ASCIISHIFT;
  
  T_ones = RESET;                                     // Counts ones place
  while(adc_val >= ONES_PLACE){
    adc_val -= ONES_PLACE;
    T_ones ++;
  }
  T_ones += ASCIISHIFT;
}

void average_left_thresh(void){
  left_detect1 = left_detect2;
  left_detect2 = left_detect3;
  left_detect3 = left_detect4;
  left_detect4 = left_detect5;
  left_detect5 = left_detect6;
  left_detect6 = left_detect7;
  left_detect7 = left_detect8;
  left_detect8 = ADC_Left_Detect;
  
  Left_Average = (left_detect1 + left_detect2 + left_detect3 + left_detect4 + left_detect5 + left_detect6 + left_detect7 + left_detect8)>> DIVIDE8;
  
}

void average_right_thresh(void){
  right_detect1 = right_detect2;
  right_detect2 = right_detect3;
  right_detect3 = right_detect4;
  right_detect5 = right_detect6;
  right_detect6 = right_detect7;
  right_detect7 = right_detect8;
  right_detect8 = ADC_Right_Detect;
  
  Right_Average = (right_detect1 + right_detect2 + right_detect3 + right_detect4 + right_detect5 + right_detect6 + right_detect7 + right_detect8)>> DIVIDE8;
  
}

void HEXtoBCD_Clock(int clock){
  int clock_temp = clock;
  
  hun_sec = RESET;
  while(clock_temp > 20000){
    clock_temp -= 20000;
    hun_sec ++;
  }
  
  ten_sec = RESET;
  while(clock_temp > 2000){
    clock_temp -=2000;
    ten_sec ++;
  }
  
  one_sec = RESET;
  while(clock_temp > 200){
    clock_temp -= 200;
    one_sec ++;
  }
  
  hun_milli_sec = RESET;
  while(clock_temp > 40){
    clock_temp -= 40;
    hun_milli_sec ++;
  }  
  
  
  hun_milli_sec += ASCIISHIFT;
  one_sec += ASCIISHIFT;
  ten_sec += ASCIISHIFT;
  hun_sec += ASCIISHIFT;
  
}