/*
 * CHOOSE_APP.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


/*
 * CHOOSE_APP.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "CHOOSE_APP_RX.h"


Uint8 Received_Data = 0 ;



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

/***********************************************************************************************************************************/
void ROOM1_LIGHT (Uint8 APP_1)
{
	if (APP_1 == 1)
	LED0_ON ();
	else if (APP_1 == 0)
	{
		LED1_ON();
		_delay_ms(10);
		LED0_OFF ();
	}
}

void ROOM2_LIGHT (Uint8 APP_2)
{
	if (APP_2 == 1)
	LED1_ON ();
	else if (APP_2 == 0)
	{	LED3_ON();
		    _delay_ms(10);
	LED1_OFF ();
	}
}


void Temp_Sensor (Uint8 APP_3)
{
	if (APP_3 == 1)
	{
	Uint16 ReadTemp = 0 ;
	LED2_ON();   // Turn FAN on                                 // while (Received_Data ==  Temp_Sensor_ON )
	ReadTemp = 30 ;
	//TempSensor_Read(&ReadTemp);
	LCD_WriteInteger (ReadTemp);

	/*while (Received_Data ==  Temp_Sensor_ON )
	{*/
	if (ReadTemp >= 40)
	{
		LED2_Toggle ();   // Turn FAN on                                 // while (Received_Data ==  Temp_Sensor_ON )
		DCMotor_SetDir(CLOCK_WISE_DIR );                                 // if (ReadTemp >= 40)
		DCMotor_SetSpeed(7);
		DCMotor_START();
	}
	else
	DCMotor_STOP();   // Turn FAN off
	}
	else if (APP_3 == 0)
    clr_bit(ADCSRA,7);

}


void Control_DOOR(Uint8 APP_4)
{

	if (APP_4 == 1)
	{
		buzzer_TOGGLE ();
		LED3_ON();

	}
	else if (APP_4 == 0)
	{
	LED3_ON();     //for simulation//
    _delay_ms(10);
	LED3_OFF ();
	}
}
/***********************************************************************************************************************************/

void Control_Applications (Uint8 TX_Data)
{


	Received_Data = SPI_TranSiver (TX_Data) ;
	LCD_WriteChar(Received_Data);
	_delay_ms(100);
	LCD_Clear ();

	if (Received_Data == 'A')
		ROOM1_LIGHT (1);

	else if (Received_Data == 'a')
		ROOM1_LIGHT (0);


	else if (Received_Data == 'B')
		ROOM2_LIGHT (1);

	else if (Received_Data == 'b')
		ROOM2_LIGHT (0);


	else if (Received_Data == 'C')
		Temp_Sensor (1);

	else if (Received_Data == 'c')
		Temp_Sensor (0);

	else if (Received_Data == 'D')
		Control_DOOR(1);
	else if (Received_Data == 'd')
		Control_DOOR(0);
}

/*	switch (Received_Data)
	{

	case ROOM1_LIGHT_ON :
		 ROOM1_LIGHT (1);
		 break;

	case ROOM1_LIGHT_OFF :
		 ROOM1_LIGHT (0);
		 break;

	case ROOM2_LIGHT_ON :
		 ROOM2_LIGHT (1);
		 break;

	case ROOM2_LIGHT_OFF :
		 ROOM2_LIGHT (0);
	     break;

	case Temp_Sensor_ON :

		Temp_Sensor (1);
		break;

	case Temp_Sensor_OFF :
		Temp_Sensor (0);
	     break;

	case Control_DOOR_ON  :
		Control_DOOR(1);
		break;

	case Control_DOOR_OFF  :
		Control_DOOR(0);
		break;

	default :
		break;

	}
}*/


/*void Control_Applications (Uint8 TX_Data)
{
	Uint8 Received_Data = 0 ;

	Received_Data = SPI_TranSiver (TX_Data) ;

	switch (Received_Data)
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

		while (Received_Data ==  Temp_Sensor_ON )
		{
		if (ReadTemp >= 40)
		{
			LED2_Toggle ();   // Turn FAN on                                 // while (Received_Data ==  Temp_Sensor_ON )
			DCMotor_SetDir(CLOCK_WISE_DIR );                                 // if (ReadTemp >= 40)
			DCMotor_SetSpeed(7);
			DCMotor_START();

		}
		else
		DCMotor_STOP();   // Turn FAN off
		}
		break;

	case Temp_Sensor_OFF :

	     clr_bit(ADCSRA,7);

	     break;

	case Control_DOOR_ON  :

		buzzer_TOGGLE ();
		LED3_ON();

		break;

	case Control_DOOR_OFF  :

		LED3_OFF();
		break;

	default :
		break;

	}

}*/

/*
void ROOM1_LIGHT (Uint8 RX_data)
{


	if (RX_data == 'A')
		{
		LED0_ON ();
		}

	else if (RX_data == 'a')
	{
		LED0_ON ();
	}

	else
	{
	   buzzer_ON ();
	   _delay_ms(100);
	   buzzer_OFF ();
	   LCD_WriteString ("Press the right button");
	}

	_delay_ms (500);
	LCD_Clear ();
}


void ROOM2_LIGHT (Uint8 RX_data)
{

	if (RX_data == 'B')
		{
		LED0_ON ();
		}

	else if (RX_data == 'b')
	{
		LED0_OFF ();
	}

	else
	{
	   buzzer_ON ();
	   _delay_ms(100);
	   buzzer_OFF ();
	   LCD_WriteString ("Press the right button");
	   _delay_ms (500);
	   	LCD_Clear ();
	}
}


void TempSensor (Uint8 RX_data)
{
	if (RX_data == 'C')
		{
		LED0_ON ();
		}

	else if (RX_data == 'c')
	{
		LED0_OFF ();
	}

	else
	{
	   buzzer_ON ();
	   _delay_ms(100);
	   buzzer_OFF ();
	   LCD_WriteString ("Press the right button");
	   _delay_ms (500);
	   	LCD_Clear ();
	}
}


void Control_Door (Uint8 RX_data)
{
	if (RX_data == 'D')
		{
		LED0_ON ();
		}

	else if (RX_data == 'd')
	{
		LED0_OFF ();
	}

	else
	{
	   buzzer_ON ();
	   _delay_ms(100);
	   buzzer_OFF ();
	   LCD_WriteString ("Press the right button");
	   _delay_ms (500);
	   	LCD_Clear ();
	}
}


*/

