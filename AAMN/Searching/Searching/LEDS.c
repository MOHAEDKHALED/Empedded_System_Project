#include "LEDS.h"

void LEDS_intiat(){

	SET_BIT(DDR_btn1,4);
	SET_BIT(DDR_btn1,5);
	SET_BIT(DDR_btn1,6);
	SET_BIT(DDR_btn2,7);
	
	CLR_BIT(PORT_btn1,4);
	CLR_BIT(PORT_btn1,5);
	CLR_BIT(PORT_btn1,6);
	CLR_BIT(PORT_btn2,7);
	
	_delay_ms(15);
}

void LEDS_on(unsigned char ch){
	if (ch==4)
	{
		SET_BIT(PORT_btn1,4);
	}
	else if (ch==3)
	{
		SET_BIT(PORT_btn1,5);
	}
	else if (ch==2)
	{
		SET_BIT(PORT_btn1,6);
	}
	else if (ch==1)
	{
		SET_BIT(PORT_btn2,7);
	}
}

void LEDS_off(unsigned char ch){
	if (ch==4)
	{
		CLR_BIT(PORT_btn1,4);
	}
	else if (ch==3)
	{
		CLR_BIT(PORT_btn1,5);
	}
	else if (ch==2)
	{
		CLR_BIT(PORT_btn1,6);
	}
	else if (ch==1)
	{
		CLR_BIT(PORT_btn2,7);
	}
}
