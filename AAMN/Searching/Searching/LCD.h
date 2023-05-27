#ifndef LCD_H_
#define LCD_H_

#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU (16000000UL)

#define LCD_data_DDR DDRB //define lcd data port direction
#define LCD_command_DDR DDRA //lcd command port direction

#define LCD_data_PORT PORTB //define lcd data port
#define LCD_command_PORT PORTA // //define lcd command  port

#define RS 3 //register select (data/command)
#define EN 2 //enable signal pin

void LCD_init(void);

void LCD_command(unsigned char cmd);

void LCD_write_char(unsigned char ch);

void LCD_write_string(char* st);

void LCD_clear(void);

void LCD_gotoRowColumn(unsigned char row , unsigned char col);





#endif /* LCD_H_ */