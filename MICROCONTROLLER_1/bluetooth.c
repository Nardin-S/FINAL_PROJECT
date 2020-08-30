/*
 * bluetooth.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "bluetooth.h"
#define  F_CPU  4000000
#include <util/delay.h>

Uint8 Bluetooth_Receive_character (void)
{

	Uint8 Char = 0 ;

	UART_InIT () ;

    Char = UART_Receive_CHAR ();

    return Char ;

}


