#include "lis3dh.h"
#include "lis3dh_driver.h"
#include <stdint.h>
#include <stm32g4xx_hal.h>


uint8_t dataBuffer[255];
LIS3DH_Aux123Raw_t aux_raw_data;

void lis3dh_initSensor(void) {
	//CTRL_REG1
	LIS3DH_WriteReg(LIS3DH_CTRL_REG1, 0b01110111);

	HAL_Delay(100);


}



void lis3dh_readSensorData(void) {

	while (!LIS3DH_GetStatusReg(dataBuffer)) {
		//wait until data is available
	}

	lis3dh_getRawAxxelData(&aux_raw_data);

}


void lis3dh_getRawAxxelData(LIS3DH_Aux123Raw_t* buff) {
  u8_t valueL;
  u8_t valueH;

  LIS3DH_ReadReg(LIS3DH_OUT_X_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_X_H, &valueH);
  buff->AUX_1 = (u16_t)( (valueH << 8) | valueL )/16;

  LIS3DH_ReadReg(LIS3DH_OUT_Y_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_Y_H, &valueH);
  buff->AUX_2 = (u16_t)( (valueH << 8) | valueL )/16;

  LIS3DH_ReadReg(LIS3DH_OUT_Z_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_Z_H, &valueH);
  buff->AUX_3 = (u16_t)( (valueH << 8) | valueL )/16;
}


