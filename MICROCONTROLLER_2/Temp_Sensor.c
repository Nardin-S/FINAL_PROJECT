/*
 * Temp_Sensor.c
 *
 *  Created on: ??�/??�/????
 *      Author: Meriam
 */


#include "Temp_Sensor.h"

void TempSensor_Initialization (void)
{

   ADC_InIT();

}



void TempSensor_Read(Uint16 * data)
{
	ADC_Read (data);

}
