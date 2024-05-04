#include "dht11.h"
#include "timer.h"
#include "main.h"
#include <stdbool.h>


void dht11_setPinInput(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT11_Sensor_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DHT11_Sensor_GPIO_Port, &GPIO_InitStruct);
}


void dht11_setPinOutput(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = DHT11_Sensor_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DHT11_Sensor_GPIO_Port, &GPIO_InitStruct);

}


void dht11_initCommunication(void) {

	dht11_setPinOutput();
	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, SET);

	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, RESET);
	timer_usDelay(18000);
	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, SET);
	timer_usDelay(30);

	dht11_setPinInput();
}


bool dht11_checkResponse(void) {
	uint8_t state = 0;

	timer_usDelay(40);
	state = HAL_GPIO_ReadPin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin);
	if (!state) {
		timer_usDelay(60);
		state = HAL_GPIO_ReadPin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin);
		if (state) {
			// Response was ok
			return true;
		}
	}
	// Communication not ok
	return false;
}


void dht11_readBit(void) {
	uint8_t state = 1;

	// Wait until Data Line is pulled LOW
	while (state) {
		state = HAL_GPIO_ReadPin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin);
	} while (!state) {
		state = HAL_GPIO_ReadPin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin);

	}
	// Check if Data Line is high
	timer_usDelay(100);
	state = HAL_GPIO_ReadPin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin);



}











