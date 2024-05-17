/*
 * lis3dh.h
 *
 *  Created on: May 14, 2024
 *      Author: matth
 */

#ifndef INC_LIS3DH_H_
#define INC_LIS3DH_H_

#include "lis3dh_driver.h"

void lis3dh_initSensor(void);
void lis3dh_readSensorData(void);
void lis3dh_getRawAxxelData(LIS3DH_Aux123Raw_t* buff);

#endif /* INC_LIS3DH_H_ */
