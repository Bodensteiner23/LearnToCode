#include "lis3dh.h"
#include "lis3dh_driver.h"
#include <stdint.h>
#include <stm32g4xx_hal.h>


uint8_t dataBuffer[255];
LIS3DH_Aux123Raw_t aux_raw_data;

void lis3dh_initSensor(void) {
	//CTRL_REG2
	LIS3DH_WriteReg(LIS3DH_CTRL_REG2, 0x0);
	//CTRL_REG3
	LIS3DH_WriteReg(LIS3DH_CTRL_REG3, 0x0);
	//CTRL_REG4
	LIS3DH_WriteReg(LIS3DH_CTRL_REG4, 0x80);
	//CTRL_REG1
	LIS3DH_WriteReg(LIS3DH_CTRL_REG1, 0x47);

	HAL_Delay(100);

	//CTRL_REG4
	LIS3DH_WriteReg(LIS3DH_CTRL_REG1, 0x82);

	HAL_Delay(100);


}



void lis3dh_readSensorData(void) {

	while (!LIS3DH_GetStatusReg(dataBuffer)) {
		//wait until data is available
	}

	LIS3DH_GetAuxRaw(&aux_raw_data);




}
