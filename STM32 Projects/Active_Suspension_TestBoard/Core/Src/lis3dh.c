#include "lis3dh.h"
#include "lis3dh_driver.h"
#include <stdint.h>


uint8_t dataBuffer[255];
LIS3DH_Aux123Raw_t aux_raw_data;

void lis3dh_initSensor(void) {
	//CTRL_REG1
	LIS3DH_WriteReg(LIS3DH_CTRL_REG1, 0b10010111);
	//CTRL_REG4
	LIS3DH_WriteReg(LIS3DH_CTRL_REG4, 0b00000100);

}



void lis3dh_readSensorData(void) {

	while (!LIS3DH_GetStatusReg(dataBuffer)) {
		//wait until data is available
	}

	LIS3DH_GetAuxRaw(&aux_raw_data);




}
