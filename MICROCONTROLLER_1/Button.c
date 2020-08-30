/*
 * Button.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "Button.h"



void Button1_initial(void){
	/* Take input from button */
	DIO_SetPinDir(DIO_PORTD,DIO_Pin0,DIO_Pin_INPUT);

}

Uint8 Button1_GetValue(void){

	Uint8 Value =0 ;
	Value = get_bit(PIND,0);
	while (get_bit(PIND,0));   /// 3shan f el dosa el wa7da ye3mel action wa7ed
    _delay_ms(20);            // 3shan ye3aleg bouncing 3o2bal ma Yedos w yesheel edo
	return Value ;

}


