#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#define F_CPU (16000000UL)

void seven_segment_init(void);
void seven_segment_display(int num);


#endif /* SEVEN_SEGMENT_H_ */