//******************************************************************************
//  File Name: functions.h
//
//  Description: This file contains the Function prototypes
//
//  Quoc Chuong Vu
//  Jan 2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.12.4)
//******************************************************************************
// Functions
//

void follow_BlackLine(void);


// MOVEMENTS
void get_on_blackline(void);
int check_BlackLine(void);
void position_BlackLine(void);
void car_forward_fast(void);
void car_forward_medium(void);
void car_forward_slow(void);

void move_counterclockwise(void);
void move_clockwise_slowly(void);
void move_clockwise(void);
void stop_car(void);
void right_forward_slow(void);
void right_forward_medium(void);
void right_forward_fast(void);
void left_forward_slow(void);
void left_forward_medium(void);
void left_forward_fast(void);
void move_counterclockwise_follow(void);
void move_clockwise_follow(void);

// ADC
void convert_ADC(void);
void HEXtoBCD_left(void);
void HEXtoBCD_right(void);
void HEXtoBCD_thumb(int);
void HEXtoBCD_Clock(int);
void average_left_thresh(void);
void average_right_thresh(void);

// ADC
void Init_ADC(void);

//Update Display

void update_display_state(void);
void project_5_main_code(void);
void LCD_intro(void);

// Figures
void Go_Circle(int direction, int duty_cycle, int timing);
void Go_Eight(void);
void Go_Triangle(void);
void Go_Angle(int angle);
void Go_Straight(int length);
void time_delay(int time);

// Initialization
void Init_Conditions(void); //Function with conditions to reset and display on the LCD
void Init_LEDs(void); //Function to control LED
void Init_Ports(void); //Function with control to the ports
void Init_Clocks(void); //Function with the clock

// Interrupts
void enable_interrupts(void); //Function to enable interrupts
__interrupt void Timer0_B0_ISR(void);
__interrupt void switch_interrupt(void);

// Analog to Digital Converter
// Clocks
void Init_Clocks(void);

// LED Configurations
void Init_LEDs(void);
void IR_LED_control(char selection);
void Backlite_control(char selection);
void toggle_IR_LED(int);
void Grn_LED_on(void);
void Red_LED_on(void);
void Grn_LED_off(void);
void Red_LED_off(void);

  // LCD
void Display_Process(void);
void Display_Update(char p_L1,char p_L2,char p_L3,char p_L4);
void enable_display_update(void);
void update_string(char *string_data, int string);
void Init_LCD(void);
void lcd_clear(void);
void lcd_putc(char c);
void lcd_puts(char *s);

void lcd_power_on(void);
void lcd_write_line1(void);
void lcd_write_line2(void);
//void lcd_draw_time_page(void);
//void lcd_power_off(void);
void lcd_enter_sleep(void);
void lcd_exit_sleep(void);
//void lcd_write(unsigned char c);
//void out_lcd(unsigned char c);

void Write_LCD_Ins(char instruction);
void Write_LCD_Data(char data);
void ClrDisplay(void);
void ClrDisplay_Buffer_0(void);
void ClrDisplay_Buffer_1(void);
void ClrDisplay_Buffer_2(void);
void ClrDisplay_Buffer_3(void);

void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void lcd_rotate(char view);

//void lcd_write(char data, char command);
void lcd_write(unsigned char c);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_write_line3(void);

void lcd_command( char data);
void LCD_test(void);
void LCD_iot_meassage_print(int nema_index);

// Menu
void Menu_Process(void);

// Ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(int port3_4);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);

// SPI
void Init_SPI_B1(void);
void SPI_B1_write(char byte);
void spi_rs_data(void);
void spi_rs_command(void);
void spi_LCD_idle(void);
void spi_LCD_active(void);
void SPI_test(void);
void WriteIns(char instruction);
void WriteData(char data);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);
void Init_Switch(void);
void Switch_Process(void);
void Switch1_Process(void);
void Switch2_Process(void);
void menu_act(void);
void menu_select(void);

// Timers
void Init_Timers(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void Init_Timer_B3(void);

void usleep(unsigned int usec);
void usleep10(unsigned int usec);
void five_msec_sleep(unsigned int msec);
void measure_delay(void);
void out_control_words(void);

void Software_Trim(void); //I don't really know

 // LEDs
void Init_All(void);


