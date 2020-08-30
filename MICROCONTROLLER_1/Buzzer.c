/*
 * Buzzer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "Buzzer.h"


void buzzer_initial (void)
{
	DIO_SetPinDir(PORTA ,DIO_Pin3 , DIO_Pin_OUTPUT);
}

void buzzer_ON (void){

	DIO_WritePin(PORTA ,DIO_Pin3  , DIO_Pin_High);
}

void buzzer_OFF (void){

	DIO_WritePin(PORTA ,DIO_Pin3 , DIO_Pin_LOW);

}

