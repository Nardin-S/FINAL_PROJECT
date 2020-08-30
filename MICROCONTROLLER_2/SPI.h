/*
 * SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Meriam
 */

#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init (void) ;

void SPI_Slave_Init  (void) ;

void SPI_Master_InitTrans (void) ;

void SPI_Master_TerminateTrans (void) ;

Uint8 SPI_TranSiver (Uint8 transmitted_data) ;


#endif /* SPI_H_ */
