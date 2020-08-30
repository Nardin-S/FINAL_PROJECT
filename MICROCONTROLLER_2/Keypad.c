/*
 * Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */


#define F_CPU 8000000UL
#include "Keypad.h"

#include <util/delay.h>


#define COL_initial  0
#define COL_Final    2

#define ROW_initial  3
#define ROW_Final    6

#define NOT_Pressed  0


const Uint8 Keypad_values[4][3] = {{'1' , '2' , '3'},
                                   {'4' , '5' , '6'},
                                   {'7' , '8' , '9'},
                                   {'*' , '0' , '#'} };

void KEYPAD_Initial (void)
{


 DIO_SetPinDir (Keypad_PORT  , Keypad_Column0  ,DIO_Pin_OUTPUT);
 DIO_SetPinDir (Keypad_PORT  , Keypad_Column1  ,DIO_Pin_OUTPUT);
 DIO_SetPinDir (Keypad_PORT  , Keypad_Column2  ,DIO_Pin_OUTPUT);

 DIO_SetPinDir (Keypad_PORT  ,  Keypad_ROW0 , DIO_Pin_INPUT);
 DIO_SetPinDir (Keypad_PORT  ,  Keypad_ROW1 , DIO_Pin_INPUT);
 DIO_SetPinDir (Keypad_PORT  ,  Keypad_ROW2  ,DIO_Pin_INPUT);
 DIO_SetPinDir (Keypad_PORT  ,  Keypad_ROW3 , DIO_Pin_INPUT);

 DIO_SetPullUp(Keypad_PORT , Keypad_ROW0);
 DIO_SetPullUp(Keypad_PORT , Keypad_ROW1);
 DIO_SetPullUp(Keypad_PORT , Keypad_ROW2);
 DIO_SetPullUp(Keypad_PORT , Keypad_ROW3);


 DIO_WritePin(Keypad_PORT,  Keypad_Column0  ,DIO_Pin_High);
 DIO_WritePin(Keypad_PORT,  Keypad_Column1  ,DIO_Pin_High);
 DIO_WritePin(Keypad_PORT,  Keypad_Column2  ,DIO_Pin_High);

}

Uint8 KEYPAD_GetValue(void)
{
	Uint8 LOC_Column = 0;
	Uint8 LOC_ROW = 0;
	Uint8 Value = 0;
	Uint8 temp = 0;

	for (LOC_Column =COL_initial; LOC_Column <=  COL_Final ; LOC_Column++)
	{
		 DIO_WritePin(Keypad_PORT, LOC_Column ,DIO_Pin_LOW);

		 for (LOC_ROW = ROW_initial; LOC_ROW <=  ROW_Final ; LOC_ROW++){

			DIO_ReadPin(Keypad_PORT, LOC_ROW  ,&temp);

			if (!temp)
			{

				Value = Keypad_values[LOC_ROW - ROW_initial ][LOC_Column - COL_initial];

				while (!temp)     //DO ONLY  ONE ACTION
				{
					DIO_ReadPin(Keypad_PORT, LOC_ROW  ,&temp);
				}

				_delay_ms(10);
			}
		 }

		 DIO_WritePin(Keypad_PORT, LOC_Column ,DIO_Pin_High);

	   }
	return Value;
}



