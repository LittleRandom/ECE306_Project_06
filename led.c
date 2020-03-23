//------------------------------------------------------------------------------
//  File Name: led.c
//
//  Description: Contains the conditions and assignments for the LEDs on MSP 430
//
//
//  Quoc Chuong Vu
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.12.4)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "macros.h"
#include  "functions.h"

void Init_LEDs(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on both LEDs
  P1OUT &= ~RED_LED;
  P6OUT &= ~GRN_LED;
//------------------------------------------------------------------------------
}

void Grn_LED_on(void){
    P6OUT  |= GRN_LED;
}

void Red_LED_on(void){
    P1OUT  |= RED_LED;
}

void Grn_LED_off(void){
    P6OUT  &= ~GRN_LED;
}

void Red_LED_off(void){
    P1OUT  &= ~RED_LED;
}

void toggle_IR_LED(int ONOFF){
      if(ONOFF) P3OUT |= IR_LED;       // ON
      else P3OUT  &= ~IR_LED;        // OFF
}