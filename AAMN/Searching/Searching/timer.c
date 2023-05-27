#include "timer.h"
#include <avr/interrupt.h>
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "std_types.h"


void (*g_callback)(void) = ((void*)0);

void timer0_init(){
	TCNT0 =0; //timer init value
	SET_BIT(TIMSK, TOIE0);
	
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<< CS00);  //1024 prescaler
	SET_BIT(SREG, 7);
}

void timer0_setCallback(void(*a_ptr)(void)){
	g_callback = a_ptr;
}


ISR(TIMER0_OVF_vect){
	static unsigned char count = 0;
	
	count++;
	
	if (count == 62) // Approximately 1 second
	{
		count = 0;
		
		if(g_callback != NULL){
			(*g_callback)();
		}
		
	}
	
}