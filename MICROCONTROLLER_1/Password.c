/*
 * Password.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#include "Password.h"
#include "Keypad.h"
#include "LCD.h"

Uint8 Check_Password(void)
{
Uint8 Entered_PW[size] ;
Uint8 Data = 0 ;
Uint8 i = 0 ;
Uint8 j = 0 ;
Uint8 flag = 0;

for (i=0 ; i < 4 ; i++)
{
	Data = KEYPAD_GetValue ();
	Entered_PW[i] = Data ;
	LCD_WriteChar('*');
}
if (i == 4)
{
   for (j=0 ; j < 4 ; j++)
   {
	   if (Entered_PW[i] == Correct_PASSWORD[j])
		   flag = 1 ;
	   else
		   flag = 0 ;
	       break ;
   }
   /*
   if (flag == 0)
	   {
	   LCD_WriteString ("incorrect password!!");
	   _delay_ms(100);
       LCD_Clear ();
	   LCD_WriteString ("Enter it again ..");
	   Check_Password();
	   }
   else if (flag == 1)
    LCD_WriteString ("Correct password!!");
   */
   return flag ;
}

}
