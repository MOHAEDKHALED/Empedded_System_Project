#ifndef LEDS_H_
#define LEDS_H_

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include <util/delay.h>
#define F_CPU (16000000UL)

#define DDR_btn1 DDRA
#define DDR_btn2 DDRB
#define PORT_btn1 PORTA
#define PORT_btn2 PORTB

void LEDS_intiat();
void LEDS_on(unsigned char ch);
void LEDS_off(unsigned char ch);



#endif /* LEDS_H_ */