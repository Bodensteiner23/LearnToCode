/*
 * lis3dh.h
 *
 *  Created on: May 14, 2024
 *      Author: matth
 */

#ifndef INC_LIS3DH_H_
#define INC_LIS3DH_H_

void lis3dh_initI2C(I2C_HandleTypeDef *_hi2c1);
void lis3dh_read_data_polling(void);

#endif /* INC_LIS3DH_H_ */
