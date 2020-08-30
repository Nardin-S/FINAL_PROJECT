/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#define F_CPU 8000000
#include "SPI.h"
#include "CHOOSE_APP_RX.h"
#include <util/delay.h>


 int main (void)
 {

	/*Uint8  transmitted_Signal = 1 ;
    Uint8 Received_Signal = 0;
*/

	//DIO_SetPinDir(DIO_PORTD ,DIO_Pin0  ,DIO_Pin_OUTPUT);/
	Control_Initialization ();

    SPI_Slave_Init  ();



	 Control_Applications(1);
	  _delay_ms(100) ;

	 while(1)
	 {



		 /*
		 Received_Signal = SPI_TranSiver (transmitted_Signal) ;

if (transmitted_Signal == 0 )
{
	 DIO_TogglePin (DIO_PORTD ,DIO_Pin0 );

	 Received_Signal = 0 ;
}
    _delay_ms(500) ;*/

	 }

 }

