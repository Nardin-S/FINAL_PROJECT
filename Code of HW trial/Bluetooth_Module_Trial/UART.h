/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef UART_H_
#define UART_H_

#include "DIO.h"
#include "UART_CONFIGURATION.h"

#define NULL ((void *)0)


void UART_InIT (void);

void UART_Transmit_CHAR (Uint8  transmitted_data);

void UART_Transmit_String (Uint8* str );

Uint8 UART_Receive_CHAR (void);

void  UART_Receive_String (void );  // TASK

#endif /* UART_H_ */
