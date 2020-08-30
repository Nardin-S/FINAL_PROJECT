/*
 * bluetooth.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "LED.h"
#include "LCD.h"
#include "Keypad.h"
#include "Buzzer.h"
#include "DIO.h"
#include "UART.h"
//#include "Bluetooth_Configuration.h"//
#include <util/delay.h>



Uint8 Bluetooth_Receive_character (void) ;

Uint8 CHOOSE_APP (void);



#endif /* BLUETOOTH_H_ */
