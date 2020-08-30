/*
 * CHOOSE_APP.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef CHOOSE_APP_RX_H_
#define CHOOSE_APP_RX_H_


#include "LED.h"
#include "LCD.h"
#include "SPI.h"
#include "Buzzer.h"
#include "DCMotor.h"
#include "Temp_Sensor.h"
#include "APPs_Configuration.h"
#include <util/delay.h>



void Control_Initialization (void);

void Control_Applications (Uint8 TX_Data);

void ROOM1_LIGHT (Uint8 APP_1);
void ROOM2_LIGHT (Uint8 APP_2);
void Temp_Sensor (Uint8 APP_3);
void Control_DOOR(Uint8 APP_4);







/*
void  ROOM1_LIGHT (Uint8 RX_data) ;

void ROOM2_LIGHT  (Uint8 RX_data) ;

void TempSensor   (Uint8 RX_data) ;

void Control_Door (Uint8 RX_data) ;
*/

#endif /* CHOOSE_APP_RX_H_ */
