/*
 * PMW0.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef PWM0_H_
#define PWM0_H_

#include "ATmega32_Registers.h"

void PWM0_Init(void);

void PWM0_Generate(Uint8 DUTY_CYCLE);

void PWM0_Start(void);


#endif /* PWM0_H_ */
