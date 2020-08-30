
/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */




#define F_CPU 8000000
#include "SPI.h"
#include "LED.h"
#include <util/delay.h>
//#include "Password.h"
#include "bluetooth.h"
#include "CHOOSE_APP.h"

int main (void)
{
/*
	LCD_initial();
	LCD_WriteString ('Welcome');
	_delay_ms(1000);
	LCD_Clear ();
   	KEYPAD_Initial ();
	Uint8 transmitted_Signal = 'A' ;
    Uint8 Received_Signal = 0;
	DIO_SetPinDir(DIO_PORTD ,DIO_Pin3 ,DIO_Pin_OUTPUT);*/

    SPI_Master_Init ();
    SPI_Master_InitTrans ();

	Uint8 Satus = 0 ;
	Satus = 'C' ;     //for simulation


	while(1)
	{

		/*Received_Signal = SPI_TranSiver (transmitted_Signal) ;*/

   //Bluetooth_Receive_character () ;
	CONTROL (Satus) ;


	/*if (Received_Signal  == 1)
		{
			 DIO_TogglePin (DIO_PORTD , DIO_Pin3 );

			 Received_Signal = 0 ;

		}*/



	}
}

