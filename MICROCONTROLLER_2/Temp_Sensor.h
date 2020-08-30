/*
 * Temp_Sensor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"
#include "DIO.h"

void TempSensor_Initialization (void);

void TempSensor_Read(Uint16 * data);

#endif /* TEMP_SENSOR_H_ */
