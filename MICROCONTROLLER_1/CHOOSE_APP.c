/*
 * CHOOSE_APP.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "CHOOSE_APP.h"



void CONTROL (Uint8 Char)
{
	Uint8 RX_Data = 0 ;
	DIO_SetPinDir(DIO_PORTD ,DIO_Pin3 ,DIO_Pin_OUTPUT);

	RX_Data = SPI_TranSiver (Char) ;

	if (RX_Data == 1)
	{
		DIO_TogglePin(DIO_PORTD ,DIO_Pin3);
	}
    _delay_ms(100) ;

}




