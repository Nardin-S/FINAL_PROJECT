/*
 * PMW0.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "PWM0.h"


void PWM0_Init(void)
{
		// set FAST PWM
		TCCR0 |= 0x48 ;

		//INVERTED OR NON_INVERTED :HERE set non_inverted
		TCCR0 |= 0x20 ;

}

void PWM0_Generate(Uint8 DUTY_CYCLE)
{
	OCR0 = ((DUTY_CYCLE * 256)/100)-1 ;
}

void PWM0_Start(void)
{
		// 64 prescaler
		TCCR0 |= 0x03 ;
}
