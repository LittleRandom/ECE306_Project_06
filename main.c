//------------------------------------------------------------------------------
//  File Name: main.c
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Quoc Chuong Vu
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.12.4)
//------------------------------------------------------------------------------

#include  <string.h>
#include "msp430.h"                        // Includes all functions that is provided in the MSP430
#include "msp430fr2355.h"                  // Includes all functions that is provided in the specified model
#include "macros.h"                        // Includes all MACROS and DEFINITIONS that is written by user
#include "functions.h"                     // Includes all functions that is written by the user.

void main(void){
  
  //------------------------------------------------------------------------------
  // Main Program
  // This is the main routine for the program. Execution of code starts here.
  // The operating system is Back Ground Fore Ground.
  //
  //------------------------------------------------------------------------------
  // Initializes ADC, LED, LCD, PORTS, EVERYTHING.
  //------------------------------------------------------------------------------
  Init_All();

  //------------------------------------------------------------------------------
  // Begining of the "While" Operating System
  //    The car will always run this portion of the code as long as there is sufficient voltage
  //------------------------------------------------------------------------------

  while(ALWAYS) {                      // Can the Operating system run

    get_on_blackline();                // Moves the car onto the blackline and positions the car

    Switches_Process();                // Check for switch state change

    Display_Process();                 // Function that enable changes in the LCD.

    update_display_state();            // Function that updates the LCD screen of the car.
    
  } // End of While Loop

  //------------------------------------------------------------------------------
} // END OF main.c




