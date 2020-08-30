/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "SPI.h"



void SPI_Master_Init (void)
{
	DIO_SetPinDir(DIO_PORTB ,DIO_Pin4  ,DIO_Pin_OUTPUT);

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin5  ,DIO_Pin_OUTPUT);

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin6  , DIO_Pin_INPUT);

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin7  ,DIO_Pin_OUTPUT);

	SPI-> SPCR =  0X53 ;

}

void SPI_Slave_Init  (void)
{

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin4  ,DIO_Pin_INPUT);     //SS'

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin5  ,DIO_Pin_INPUT);     //MOSI

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin6  , DIO_Pin_OUTPUT);   //MISO

	DIO_SetPinDir(DIO_PORTB ,DIO_Pin7  ,DIO_Pin_INPUT);     //SCK

	SPI-> SPCR =  0X43 ;
}

void SPI_Master_InitTrans (void)
{
	DIO_WritePin(DIO_PORTB , DIO_Pin4  ,DIO_Pin_LOW);


}

void SPI_Master_TerminateTrans (void)
{
	DIO_WritePin(DIO_PORTB , DIO_Pin4  ,DIO_Pin_High);

}

Uint8 SPI_TranSiver (Uint8 transmitted_data)
{

	Uint8 Received_Data = 0 ;
	SPI->SPDR = transmitted_data ;
	while (get_bit(SPI->SPSR,7) == 0);
	Received_Data = SPI->SPDR ;
	return Received_Data ;

}
