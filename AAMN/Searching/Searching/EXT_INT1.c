/*
 * EXT_INT1.c
 *
 * Mohamed Khaled Mohamed Mohamed Ali Idris / CS / 2021381 / G6
 *
 * Created: 5/8/2023 7:49:29 PM
 * Author : MOHAMED_KHALED
 */
#include "EXT_INT1.h"
#include "BIT_MATH.h"
#include "std_types.h"
#include <avr/interrupt.h>


#define I_Bit (7)
void (*g_callBackPtr)(void)= NULL_PTR;
ISR(INT1_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void INT1_Init(void)
{
	CLR_BIT(SREG,I_Bit);
	CLR_BIT(DDRD,PD3);
	SET_BIT(PORTD,PD3);
	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(SREG,I_Bit);
}

void INT1_setCallBack(void (*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}