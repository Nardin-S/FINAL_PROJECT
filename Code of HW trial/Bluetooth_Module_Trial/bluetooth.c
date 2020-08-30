/*
 * bluetooth.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "bluetooth.h"

#include "LED.h"
#include "LCD.h"
//#include "SPI.h"
#include "Buzzer.h"
#include "DCMotor.h"
#include "Temp_Sensor.h"
#include "APPs_Configuration.h"

#define  F_CPU  16000000
#include <util/delay.h>



void Control_Initialization (void)
{
	LED0_initial ();
	LED1_initial ();
	LED2_initial ();
	LED3_initial ();

	LCD_initial  ();
    DCMotor_Initial();
	buzzer_initial ();
	TempSensor_Initialization ();

}

void Bluetooth_Receive_character (void)
{
	// INITIALIZATION //

	DIO_SetPinDir( DIO_PORTD ,DIO_Pin0  , DIO_Pin_INPUT) ;
/*	DIO_SetPinDir( DIO_PORTD ,DIO_Pin1  , DIO_Pin_OUTPUT);
*/


	Uint8 Char = 0 ;
	Uint16 ReadTemp = 0 ;


	UART_InIT () ;

    Char = UART_Receive_CHAR ();

	switch (Char)
	{

	case ROOM1_LIGHT_ON :
		LED0_ON ();
		break;

	case ROOM1_LIGHT_OFF :
		LED0_OFF ();
		break;

	case ROOM2_LIGHT_ON :
		LED1_ON();
		break;

	case ROOM2_LIGHT_OFF :
		LED1_OFF();
		break;

	case Temp_Sensor_ON :

		TempSensor_Read(&ReadTemp);
		LCD_WriteInteger (ReadTemp);

		if (ReadTemp >= 40)
		{
			LED2_Toggle ();   // Turn FAN on
			DCMotor_SetDir(CLOCK_WISE_DIR );
			DCMotor_SetSpeed(7);
			DCMotor_START();

		}
		else
		DCMotor_STOP();   // Turn FAN off

		break;

	case Temp_Sensor_OFF :

	     clr_bit(ADCSRA,7);

	     break;

	case Control_DOOR_ON  :

		buzzer_TOGGLE ();
		LED2_ON();

		break;

	case Control_DOOR_OFF  :

		LED2_OFF();
		break;

	default :
		break;

	}

}
/*
	else
	{
	   buzzer_ON ();
	   _delay_ms(100);
	   buzzer_OFF ();
	   LCD_WriteChar('M');

	}

	_delay_ms (500);
	LCD_Clear ();


}
*/
