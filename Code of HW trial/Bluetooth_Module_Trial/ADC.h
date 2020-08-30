/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef ADC_H_
#define ADC_H_

#include "ATmega32_Registers.h"
#include "BitMath.h"
#include "ADC_confg.h"


/************************** Reference selection *******************************/

#define ADC_VREF_AVCC            0

#define ADC_VREF_AVREF           1

#define ADC_VREF_INTERNAL        2

/****************************** ADLAR *****************************************/

#define ADC_RIGHT_ADJUST         0

#define ADC_LEFT_ADJUST          1

/*************************** Select Analog channel *****************************/


#define ADC_CHANNEL_0            0
#define ADC_CHANNEL_1            1
#define ADC_CHANNEL_2            2
#define ADC_CHANNEL_3            3
#define ADC_CHANNEL_4            4
#define ADC_CHANNEL_5            5
#define ADC_CHANNEL_6            6
#define ADC_CHANNEL_7            7



#define ADC_AUTO_TRIGGER         0

#define ADC_PRESC_128            0

#define ADC_INTERRUPT_DISABLE    0




/***************************** APIs ************************************/

void ADC_InIT(void);

void ADC_Read (Uint16* value);




#endif /* ADC_H_ */
