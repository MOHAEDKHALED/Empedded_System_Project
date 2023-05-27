#include "LCD.h"

void LCD_init(void){
	SET_BIT(LCD_command_DDR,EN);
	SET_BIT(LCD_command_DDR,RS);
	
	SET_BIT(LCD_data_DDR,0);
	SET_BIT(LCD_data_DDR,1);
	SET_BIT(LCD_data_DDR,2);
	SET_BIT(LCD_data_DDR,4);
	
	_delay_ms(15);
	LCD_command(0x02);
	LCD_command(0x28);
	LCD_command(0x0c);
	LCD_command(0x80);
	LCD_command(0x01);
}

void LCD_command(unsigned char cmd){
	CLR_BIT(LCD_command_PORT,RS);
	
	LCD_data_PORT&=0b11101000;
	unsigned char high=((cmd&0xf0)>>4);
	unsigned char temp=(high&0b00001000)<<1|(high&0b00000111);
	LCD_data_PORT|=temp;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	
	LCD_data_PORT&=0b11101000;
	unsigned char low=((cmd&0x0f));
	unsigned char temp2=(low&0b00001000)<<1|(low&0b00000111);
	LCD_data_PORT|=temp2;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	_delay_ms(5);
}

void LCD_write_char(unsigned char chr){
	SET_BIT(LCD_command_PORT,RS);
	
	LCD_data_PORT&=0b11101000;
	unsigned char high=((chr&0xf0)>>4);
	unsigned char temp=(high&0b00001000)<<1|(high&0b00000111);
	LCD_data_PORT|=temp;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	
	LCD_data_PORT&=0b11101000;
	unsigned char low=((chr&0x0f));
	unsigned char temp2=(low&0b00001000)<<1|(low&0b00000111);
	LCD_data_PORT|=temp2;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	_delay_ms(5);
}

void LCD_write_string(char* str){
	for (int i=0;str[i]!='\0';i++)
	{
		LCD_write_char(str[i]);
	}
}
void LCD_clear(void){
	LCD_command(0x01);
}
void LCD_gotoRowColumn(unsigned char row , unsigned char col)
{
	unsigned char Address=0;
	switch(row)
	{
		case 0:
		Address=col;
		break;
		case 1:
		Address=col+0x40;
		break;
		case 2:
		Address=col+0x14;
		break;
		case 3:
		Address=col+0x54;
		break;
		
	}
}