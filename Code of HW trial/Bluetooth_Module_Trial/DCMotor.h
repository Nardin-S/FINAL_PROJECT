/*
 * MOOTOR.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef MOOTOR_H_
#define MOOTOR_H_


#include "DIO.h"
//#include "timer.h"
#include "PWM0.h"

typedef enum
{

	CLOCK_WISE_DIR ,

	ANTI_CLOCK_WISE_DIR

}DC_MOTOR_DIR;

void DCMotor_START(void);

void DCMotor_Initial(void);

void DCMotor_SetSpeed(Uint8 Speed);

void DCMotor_SetDir(DC_MOTOR_DIR  direction);

void DCMotor_STOP(void);

#endif /* MOOTOR_H_ */
