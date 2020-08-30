/*
 * MOTOR.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "DCMotor.h"


void DCMotor_Initial(void)
{
	DIO_SetPinDir(DIO_PORTC ,DIO_Pin3  ,DIO_Pin_OUTPUT);
	DIO_SetPinDir(DIO_PORTC ,DIO_Pin4  ,DIO_Pin_OUTPUT);
	DIO_SetPinDir(DIO_PORTB ,DIO_Pin3  ,DIO_Pin_OUTPUT);

	PWM0_Init();
}

void DCMotor_SetSpeed(Uint8 Speed)
{

	Speed *= 10 ;

	PWM0_Generate (Speed);

}

void DCMotor_SetDir(DC_MOTOR_DIR  direction)
{

	switch(direction)
	{
	case CLOCK_WISE_DIR:
	DIO_WritePin(DIO_PORTC ,DIO_Pin3 , DIO_Pin_High );
	DIO_WritePin(DIO_PORTC ,DIO_Pin4 , DIO_Pin_LOW );
	break;

	case ANTI_CLOCK_WISE_DIR :
	DIO_WritePin(DIO_PORTC ,DIO_Pin3 , DIO_Pin_LOW  );
	DIO_WritePin(DIO_PORTC ,DIO_Pin4 , DIO_Pin_High );
	break;

	default :
		break;
	}

}

void DCMotor_START(void)
{
	PWM0_Start ();
}

void DCMotor_STOP(void)
{
	DIO_WritePin(DIO_PORTC ,DIO_Pin3 , DIO_Pin_LOW );
	DIO_WritePin(DIO_PORTC ,DIO_Pin4 , DIO_Pin_LOW );
}
