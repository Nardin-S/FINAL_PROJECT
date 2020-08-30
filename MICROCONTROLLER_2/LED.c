/*
 * LED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#include "LED.h"


void LED0_initial(void){
/****** Set PIN that corresponds to bit of LED0 as an OUTPUT ******/
	DIO_SetPinDir(DIO_PORTC,DIO_Pin2,DIO_Pin_High);
}

void LED0_ON (void){
	/****** SET LED ON(output=1) on pin correspnding to the  bit of LED0 ******/
	DIO_WritePin(DIO_PORTC,DIO_Pin2,DIO_Pin_High);

}

void LED0_OFF (void){
	/****** SET LED OFF(output=0) on pin correspnding to the  bit of LED0 ******/
	DIO_WritePin(DIO_PORTC,DIO_Pin2,DIO_Pin_LOW);

}

void LED0_Toggle (void){
/****** TOGGLE THE LED on pin correspnding to the  bit of LED0 ******/
	//DIO_TogglePin(DIO_PORTC , DIO_Pin2 , );
	toggle(PORTC,2);
}

/*********************************************************************************************/


//LED 1 //

void LED1_initial(void){
/****** Set PIN that corresponds to bit of LED0 as an OUTPUT ******/
	Set_bit(DDRC,7);
}

void LED1_ON (void){
	/****** SET LED ON(output=1) on pin correspnding to the  bit of LED0 ******/
	Set_bit(PORTC,7);
}

void LED1_OFF (void){
	/****** SET LED OFF(output=0) on pin correspnding to the  bit of LED0 ******/
	clr_bit(PORTC,7);
}

void LED1_Toggle (void){
/****** TOGGLE THE LED on pin correspnding to the  bit of LED0 ******/
	toggle(PORTC,7);
}

/*******************************************************************************************************/

// LED 2 //

void LED2_initial(void){
/****** Set PIN that corresponds to bit of LED0 as an OUTPUT ******/
	Set_bit(DDRA,0);
}

void LED2_ON (void){
	/****** SET LED ON(output=1) on pin correspnding to the  bit of LED0 ******/
	Set_bit(PORTA,0);
}

void LED2_OFF (void){
	/****** SET LED OFF(output=0) on pin correspnding to the  bit of LED0 ******/
	clr_bit(PORTA,0);
}

void LED2_Toggle (void){
/****** TOGGLE THE LED on pin correspnding to the  bit of LED0 ******/
	toggle(PORTA,0);
}



// LED 3 //

void LED3_initial(void){
/****** Set PIN that corresponds to bit of LED0 as an OUTPUT ******/
	Set_bit(DDRA,2);
}

void LED3_ON (void){
	/****** SET LED ON(output=1) on pin correspnding to the  bit of LED0 ******/
	Set_bit(PORTA,2);
}

void LED3_OFF (void){
	/****** SET LED OFF(output=0) on pin correspnding to the  bit of LED0 ******/
	clr_bit(PORTA,2);
}

void LED3_Toggle (void){
/****** TOGGLE THE LED on pin correspnding to the  bit of LED0 ******/
	toggle(PORTA,2);
}
