/*
 * Buzzer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define F_cpu 16000000
#include "DIO.h"

#include <util/delay.h>

void buzzer_initial (void);

void buzzer_ON (void);

void buzzer_OFF (void);

void buzzer_TOGGLE (void);


#endif /* BUZZER_H_ */
