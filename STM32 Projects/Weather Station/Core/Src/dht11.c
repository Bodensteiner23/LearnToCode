#include "dht11.h"
#include "main.h"


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
	us_delay(18000);
	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, SET);
	us_delay(30);

	dht11_setPinInput();
}