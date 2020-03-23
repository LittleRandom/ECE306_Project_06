// ------------------------------------------------------------------------------
//  File Name: macros.h
//
//  Description: This file contains all DEFINES and Global Variables
//
//  Quoc Chuong Vu      
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V7.12.4
// ------------------------------------------------------------------------------
// MACROS========================================================================

//TURN 90
#define TURNED                  (1)
#define TURN90_TIME             (160)
#define MOVE_TO_CENTER_TIME     (250)

// BLACK LINE DETECTION
#define LEFT_THRESH             (90)
#define RIGHT_THRESH            (120)
#define BOTH                    (1)
#define LW_RB                   (2)
#define LB_RW                   (3)
#define STOP_CAR                (5)
#define FOLLOW_BLACKLINE        (6)
#define CHECK                   (7)
#define DONE                    (8)
#define FOLLOW_HOLD             (0)
#define FOLLOW_START            (1)
#define FOLLOW_CORRECT_LB_RW    (2)
#define FOLLOW_CORRECT_LW_RB    (3)
#define FOLLOW_DONE             (11)
#define MOVE_TO_MIDDLE          (5)
#define TURN_90                 (7)
#define TURN_90_FINISHED         (8)
#define PROJECT_7_FINISHED      (10)

// CCR
#define CCR1                    (2)
#define CCR2                    (4)
#define CCR_RESET               (14)

// TIMES
#define HALF                    (100)
#define ONE                     (200)
#define TWO                     (400)
#define THREE_SECONDS           (600)
#define TEN_MS                  (5)
#define CIRCLE_2                (5756)

// DISPLAY      
#define CHAR0                   (0)
#define CHAR1                   (1)
#define CHAR2                   (2)
#define CHAR3                   (3)
#define CHAR4                   (4)
#define CHAR5                   (5)
#define CHAR6                   (6)
#define CHAR7                   (7)
#define CHAR8                   (8)
#define CHAR9                   (9)
#define CHAR10                  (10)
#define CHAR11                  (11)
#define NUM_OF_LINES            (4)
#define NUM_OF_CHARS            (11)
#define HUNDRED_MS              (20)

// HEX
#define ASCIISHIFT              (0x30)
#define ONES_PLACE              (1)
#define TENS_PLACE              (10)
#define HUNDREDS_PLACE          (100)
#define THOUSANDS_PLACE         (1000)

// ADC
#define THUMB                   (0x0)
#define LEFT_IR_DETECT          (0x1)
#define RIGHT_IR_DETECT         (0x2)
#define DIVIDE4                 (0x02)
#define DIVIDE8                 (0x03)
#define RESETADC                (0x03)

// Car movement states
#define HOLD                    (0)
#define MOVE                    (1)
#define BLACKLINE               (2)
#define ON_BLACKLINE            (3)

// PWM
#define WHEEL_PERIOD            (1000)
#define WHEEL_OFF               (0)
#define RIGHT_FORWARD_SPEED     (TB3CCR1)
#define LEFT_FORWARD_SPEED      (TB3CCR2)
#define RIGHT_REVERSE_SPEED     (TB3CCR3)
#define LEFT_REVERSE_SPEED      (TB3CCR4)
#define STOP                    (0)
#define LEFT_SLOW               (600)
#define LEFT_MEDIUM             (750)
#define LEFT_FAST               (999)
#define RIGHT_SLOW              (600)
#define RIGHT_MEDIUM            (800)
#define RIGHT_FAST              (999)
#define LEFT_CLOCKWISE          (850)
#define RIGHT_CLOCKWISE         (750)
#define RIGHT_COUNTERCLOCKWISE  (850)
#define LEFT_COUNTERCLOCKWISE   (750)
#define RIGHT_CLOCKWISE_SLOWLY  (600)


// ON OFF STATE
#define ON                      (1)
#define OFF                     (0)

#define TRUE                    (1)
#define FALSE                   (0)

#define CHANGE_DISPLAY_ON       (1)
#define CHANGE_DISPLAY_OFF      (0)

      //TB0
#define TB0CCR0_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB0CCR1_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB0CCR2_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
   
      //TB1
#define TB1CCR0_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB1CCR1_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB1CCR2_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)


      //TB2
#define TB2CCR0_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB2CCR1_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB2CCR2_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)


      //TB3
#define TB3CCR0_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR1_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR2_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR3_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR4_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR5_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)
#define TB3CCR6_INTERVAL    (2500) // 8,000,000 / 2 / 8 / (1 / 5msec)

#define TIMERB0_CCR0_VECTOR (TIMER0_B0_VECTOR)
#define TIMERB0_CCR1_VECTOR (TIMER0_B1_VECTOR)
#define TIMERB0_CCR2_VECTOR (TIMER0_B2_VECTOR)


    // USE CASES
#define RESET                   (0)
#define ZERO                    (0) // 0
#define ALWAYS                  (1) // Condition will always be true
#define RESET_STATE             (0) // Beginning State
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1

    // LCD Display
#define DISPLAY_LINE_0          (0) // line 0 from string/char array
#define DISPLAY_LINE_1          (1) // line 1 from string/char array
#define DISPLAY_LINE_2          (2) // line 2 from string/char array
#define DISPLAY_LINE_3          (3) // line 3 from string/char array

#define DISPLAY_POSITION_END    (10) // The furthest right position on LCD
#define DISPLAY_POSITION_FRONT  (0) // The furthest left position on LCD
#define DISPLAY_CHAR_BLANK      (0) // Display code for a blank
#define DISPLAY_ZERO_INDEX      (0) // The zeroeth index of display
#define DISPLAY_NUM_INDEX       (11) // Number of characters in display

#define NUM_LINE                (4) // Number of lines displayed
#define LCD_LINE_0              (0) // line 0 on LCD screen
#define LCD_LINE_1              (1) // line 1 on LCD screen
#define LCD_LINE_2              (2) // line 2 on LCD screen
#define LCD_LINE_3              (3) // line 3 on LCD screen

#define UPDATE_DISPLAY_FALSE    (0) // sets condition of updating display to 0
#define DISPLAY_COUNT_START     (0) // sets the display updater count to 0
  // Main States
    // States
#define STATE_0                 (50) // states that the main function goes through
#define STATE_1                 (100) // increments by 50 ticks
#define STATE_2                 (150) // 50 ticks = 250ms , 5 ticks = 25ms, 1 tick = 5 msec.
#define STATE_3                 (200)
#define STATE_4                 (250)

#define ONE_TIME_FALSE          (0) // FALSE to stop stop main function from taking new tasks while doing one.

#define TIME_SEQUENCE_RESET     (0) // Resets the time sequence to specified number
#define UPDATE_DISPLAY_TRUE     (1) // Sends a true to module allowing for display to change.

// Port 1 Pins
#define RED_LED                 (0x01) // 0 RED LED 0
#define A1_SEEED                (0x02) // 1 A1_SEEED
#define V_DETECT_L              (0x04) // 2 V_DETECT_L
#define V_DETECT_R              (0x08) // 3 V_DETECT_R
#define A4_SEEED                (0x10) // 4 A4_ SEEED
#define V_THUMB                 (0x20) // 5 V_THUMB
#define UCA0RXD                 (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD                 (0x80) // 7 Back Channel UCA0TXD

// Port 2 Pins
#define P2_0                    (0x01) // 0
#define P2_1                    (0x02) // 1
#define P2_2                    (0x04) // 2
#define SW2                     (0x08) // 3 SW2
#define P2_4                    (0x10) // 4
#define P2_5                    (0x20) // 5
#define LFXOUT                  (0x40) // XOUTR
#define LFXIN                   (0x80) // XINR

// Port 3 Pins
#define TEST_PROB               (0x01) // 0 TEST PROBE
#define CHECK_BAT               (0x02) // 1 CHECK_BAT
#define OA2N                    (0x04) // 2 Photodiode Circuit
#define OA2P                    (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT               (0x10) // 4 SMCLK
#define IR_LED                  (0x20) // 5 IR_LED
#define IOT_LINK                (0x40) // 6 IOT_LINK
#define P3_7                    (0x80) // 7 P3_7

#define USE_GPIO                (0x00) // Sets Port 3.4 to a GPIO pin
#define USE_SMCLK               (0x01) // Sets Port 3.4 to a SMCLK pin

// Port 4 Pins
#define RESET_LCD               (0x01) // 0 LCD Reset
#define SW1                     (0x02) // 1 SW1
#define UCA1RXD                 (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD                 (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD             (0x10) // 4 Chip Select
#define UCB1CLK                 (0x20) // 5 SPI mode clock output UCB1CLK
#define UCB1SIMO                (0x40) // 6 UCB1SIMO
#define UCB1SOMI                (0x80) // 7 UCB1SOMI

// Port 5 Pins
#define IOT_RESET               (0x01) // 0 IOT_RESET
#define V_BAT                   (0x02) // 1 
#define IOT_PROG_SEL            (0x04) // 2
#define V_3_3                   (0x08) // 3 
#define IOT_PROG_MODE           (0x10) // 4

// Port 6 Pins
#define R_FORWARD               (0x01) // 0
#define L_FORWARD               (0x02) // 1
#define R_REVERSE               (0x04) // 2
#define L_REVERSE               (0x08) // 3 
#define LCD_BACKLITE            (0x10) // 4
#define P6_5                    (0x20) // 5
#define GRN_LED                 (0x40) // XOUTR

#define FULL_MASK               (0xFF) // Every bit = 1 for FULL MASK
#define EMPTY_MASK              (0x00) // Every bit = 0 for EMPTY MASK


// Port 3 GPIO/ SMCLK macros

#define USE_GPIO                (0x00)
#define USE_SMCLK               (0x01)
