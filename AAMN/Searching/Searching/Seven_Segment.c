#include "Seven_Segment.h"
void seven_segment_init(void)
{
	
	SET_BIT(DDRB ,0);
	SET_BIT(DDRB ,1);
	SET_BIT(DDRB ,2);
	SET_BIT(DDRB ,4);
	SET_BIT(PORTB,6);
	SET_BIT(PORTB,5);
}


void seven_segment_display(int num)
{
	if(num<10)
	{
		PORTB &= 0b11101000;
		PORTB |= (((num & 0b00001000) <<1) | (num & 0b00000111));
	}
	else
	{
		int num1=num-10;
		PORTB &= 0b11101000;
		PORTB |= (((num1 & 0b00001000) <<1) | (num1 & 0b00000111));
	}


}

