#include "lis3dh.h"
#include "lis3dh_driver.h"
#include <stdint.h>
#include <stm32g4xx_hal.h>


static uint8_t dataBuffer[255];
static LIS3DH_Aux123Raw_t aux_data;

void lis3dh_initSensor(void) {
	//CTRL_REG1
	LIS3DH_WriteReg(LIS3DH_CTRL_REG1, 0b01110111);

	HAL_Delay(100);


}



void lis3dh_readSensorData(void) {

	if (!LIS3DH_GetStatusReg(dataBuffer)) {
		//wait until data is available
		return;
	}

	lis3dh_getAxxelData(&aux_data);

	// Handover Data to Matlab Model here
	// Like this:
	//	float aux_X = aux_data.AUX_X;

}


void lis3dh_getAxxelData(LIS3DH_Aux123Raw_t* buff) {
  u8_t valueL;
  u8_t valueH;

  LIS3DH_ReadReg(LIS3DH_OUT_X_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_X_H, &valueH);
  buff->AUX_X = (u16_t) (((valueH << 8) | valueL ) / 16) * 0.001 * 9.81;

  LIS3DH_ReadReg(LIS3DH_OUT_Y_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_Y_H, &valueH);
  buff->AUX_Y = (u16_t) (((valueH << 8) | valueL ) / 16) * 0.001 * 9.81;

  LIS3DH_ReadReg(LIS3DH_OUT_Z_L, &valueL);
  LIS3DH_ReadReg(LIS3DH_OUT_Z_H, &valueH);
  buff->AUX_Z = (u16_t) (((valueH << 8) | valueL ) / 16) * 0.001 * 9.81;
}


