/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "UART.h"

//#define BR_VALUE  ((Uint32)(FOSC / (16*BaudRate)) - 1)

void UART_InIT (void)
{

	Uint32 BR_VALUE = 0 ;

    DIO_SetPinDir(DIO_PORTD ,DIO_Pin0  ,DIO_Pin_INPUT );     //RX_PIN
	DIO_SetPinDir(DIO_PORTD ,DIO_Pin1  ,DIO_Pin_OUTPUT);     //TX_PIN

	UCSRB |= 0x18 ;      /*ENABLE Receiving w Transmit */

	UCSRC |= 0x86 ;      /* num of bits */

	//Uint32 BR_VALUE = ((FOSC / (16*BaudRate)) - 1) ;


	BR_VALUE = ((80000) / (16 * (96))) -1;

	UBRRL = BR_VALUE;
}

void UART_Transmit_CHAR (Uint8   transmitted_data)
{

    while (get_bit(UCSRA,5) == 0);    //WHEN UDRE = 0 , it sets when data register is empty and ready to receive new data
	UDR = transmitted_data ;

}


void UART_Transmit_String (Uint8* str )
{
	Uint8 i = 0 ;

	while( str[i] !=  '\0')
	{
		UART_Transmit_CHAR (str[i] );
		i++;

	}

}


Uint8 UART_Receive_CHAR (void)
{
	Uint8 data = 0 ;

	while(get_bit(UCSRA,7) == 0);   //WAIT TILL NEW DATA COME

	data = UDR ;

	return  data ;

}
/*****Polling******/

Uint8* UART_Receive_String_POLLING (void)
{
	static Uint8 str[50] = {'N'} ;

	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = UART_Receive_CHAR() ;
		i++ ;
	}

	return str ;

}


/*

void UART_RX_String_Interrupt (void)
{
	SREG  = 0x80 ;
	//UCSRB |= 0x80 ;

}


ISR (USART_RXC_vect)
{
	Uint8* str ;
	int i = 0 ;
	while (UDR !=  '\0')
	{
		str[i] = UDR ;
		i++ ;
	}
	while( UDR !=  '\0')
	{
		str[i] = UART_RX_CHAR ();
		i++;
	}
}
*/

