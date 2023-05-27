//#include <avr/io.h>
#include <util/delay.h>
#include "KEYPAD.h"
#include "LCD.h"
#include "Seven_Segment.h"
#include "LEDS.h"
#include "timer.h"
#include "std_types.h"

/*void write()
{
	LEDS_off(1);
	LEDS_off(2);
	LEDS_off(3);
	LEDS_off(4);
}
*/
int main(void)
{
	seven_segment_init();	
	LEDS_intiat();
	LCD_init();
	keypad_init();
    
	
	unsigned char value;
	int list_length=0;
	char list[16];
	int index_list[16]={-1 , -1 , -1 , -1 , -1 , -1 , -1 , -1, -1, -1 , -1, -1 , -1, -1 , -1 ,-1}; ///[1 2 5] 
	int binary_list[16]={0000 , 0001 , 0010 , 0011 , 0100 , 0101 , 0110 , 0111, 1000, 1001 , 1010, 1011 , 1100, 1101 , 1110 , 1111};
	int index=0;
	char searchNum, sn;
	int l=0, x=0;
 
	LCD_write_string("   press on/c to enter nums and = to end" ); 
	while (1)
	{
		
		value=keypad_get_value();

		if (value!=INVALID_KEYPAD_PRESS)
		{
			if (value=='0') {LCD_write_char('7'); list[list_length]='7';}
			else if (value=='1') {LCD_write_char('8'); list[list_length]='8';}
			else if (value=='2') {LCD_write_char('9'); list[list_length]='9';}
			else if (value=='4') {LCD_write_char('4'); list[list_length]='4';}
			else if (value=='5') {LCD_write_char('5'); list[list_length]='5';}
			else if (value=='6') {LCD_write_char('6'); list[list_length]='6';}
			else if (value=='8') {LCD_write_char('1'); list[list_length]='1';}
			else if (value=='9') {LCD_write_char('2'); list[list_length]='2';}
			else if (value=='A') {LCD_write_char('3'); list[list_length]='3';}
			else if (value=='C') {LCD_clear();list_length=0;continue;}
			else if (value=='D') {LCD_write_char('0'); list[list_length]='0';}
			else if (value=='E') {break; }
			LCD_write_char(',');
			seven_segment_display(list[list_length]-'0');
			list_length++;
			
		}	
		
		if(list_length==16){
			break;
		}
	}

	LCD_clear();
	LCD_write_string(" Enter search number:" ); 

	while (1)
	{
		searchNum=keypad_get_value();
		if (searchNum!=INVALID_KEYPAD_PRESS)
		{
			break;
		}
     }
	
			if (searchNum=='0') {LCD_write_char('7'); searchNum='7';}
			else if (searchNum=='1') {LCD_write_char('8'); searchNum='8';}
			else if (searchNum=='2') {LCD_write_char('9'); searchNum='9';}
			else if (searchNum=='4') {LCD_write_char('4'); searchNum='4';}
			else if (searchNum=='5') {LCD_write_char('5'); searchNum='5';}
			else if (searchNum=='6') {LCD_write_char('6'); searchNum='6';}
			else if (searchNum=='8') {LCD_write_char('1'); searchNum='1';}
			else if (searchNum=='9') {LCD_write_char('2'); searchNum='2';}
			else if (searchNum=='A') {LCD_write_char('3');searchNum='3';}
			else if (searchNum=='C') {LCD_clear(); LCD_write_string("Enter search num:"); }
			else if (searchNum=='D') {LCD_write_char('0');searchNum='0';}
			else {searchNum='1';}
				
		
	     l=0;
		 while(l<list_length) {
		if (list[l] == searchNum) {
			index_list[index]=l;
			index++;
			seven_segment_display(l);
			if(l==0){LEDS_off(4);LEDS_off(3);LEDS_off(2);LEDS_off(1);}
				else if(l==1){LEDS_off(4);LEDS_off(3);LEDS_off(2);LEDS_on(1);}
				else if(l==2){LEDS_off(4);LEDS_off(3);LEDS_on(2);LEDS_off(1);}
				else if(l==3){LEDS_off(4);LEDS_off(3);LEDS_on(2);LEDS_on(1);}
				else if(l==4){LEDS_off(4);LEDS_on(3);LEDS_off(2);LEDS_off(1);}
				else if(l==5){LEDS_off(4);LEDS_on(3);LEDS_off(2);LEDS_on(1);}
				else if(l==6){LEDS_off(4);LEDS_on(3);LEDS_on(2);LEDS_off(1);}
				else if(l==7){LEDS_off(4);LEDS_on(3);LEDS_on(2);LEDS_on(1);}
				else if(l==8){LEDS_on(4);LEDS_off(3);LEDS_off(2);LEDS_off(1);}
				else if(l==9){LEDS_on(4);LEDS_off(3);LEDS_off(2);LEDS_on(1);}
				else if(l==10){LEDS_on(4);LEDS_off(3);LEDS_on(2);LEDS_off(1);}
				else if(l==11){LEDS_on(4);LEDS_off(3);LEDS_on(2);LEDS_on(1);}
				else if(l==12){LEDS_on(4);LEDS_on(3);LEDS_off(2);LEDS_off(1);}
				else if(l==13){LEDS_on(4);LEDS_on(3);LEDS_off(2);LEDS_on(1);}
				else if(l==14){LEDS_on(4);LEDS_on(3);LEDS_on(2);LEDS_off(1);}
				else if(l==15){LEDS_on(4);LEDS_on(3);LEDS_on(2);LEDS_on(1);}
				_delay_ms(20000);
				//timer0_init();		   
		        //timer0_setCallback(write);
		}
		l++;
		
	}
          
		   
		}
				
	       	
	       			
	
