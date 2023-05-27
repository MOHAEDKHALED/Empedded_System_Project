#include "KEYPAD.h"

const unsigned char arr[4][4]= {{'0','1','2','3'},
{'4','5','6','7'},
{'8','9','A','B'},
{'C','D','E','F'}
};
void keypad_init(){
	
	CLR_BIT(DDRD,3);
	CLR_BIT(DDRD,5);
	CLR_BIT(DDRD,6);
	CLR_BIT(DDRD,7); //set column as input
	
	SET_BIT(PORTD,3);
	SET_BIT(PORTD,5);
	SET_BIT(PORTD,6);
	SET_BIT(PORTD,7); //set column pull up
	
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5); //set rows as output
	
	_delay_ms(5);
}
unsigned char keypad_get_value(void){
	unsigned char col,row,ans = INVALID_KEYPAD_PRESS;
	for (row=5;row>=2;row--)
	{
		PORTC |= 0b00111100; //write high on all rows
		CLR_BIT(PORTC,row); //write low on one row
		for (col=7;col>=3;col--)
		{
			if (col==4)
			{
				col--;
			}
			if (GET_BIT(PIND,col)==0)
			{
				_delay_ms(180); //for debouncing
				if (GET_BIT(PIND,col)==0)
				{
					if (col==3)
					{
						ans=arr[5-row][7-col-1];
						break;
					}
					else
					{
						ans=arr[5-row][7-col];
						break;
					}
					
				}
			}
		}
	}
	return ans;
}