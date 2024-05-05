/*****
 *	modul: dht11.c
 *
 *	created on: 29.04.2024
 *	author: Matthias Bodensteiner
 *****/
#include "dht11.h"
#include "timer.h"
#include "gpio.h"
#include "hw_init.h"
#include "main.h"
#include <stdbool.h>

gpio_t *hw_pins;

// Handover HW struct
void hw_init_pins(gpio_t *_hw_pins) {
	hw_pins = _hw_pins;
}


void dht11_initCommunication(void) {

	gpio_setPinOutput(hw_pins->dht11_port, hw_pins->dht11_pin);
	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, SET);

	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, RESET);
	timer_usDelay(18000);
	HAL_GPIO_WritePin(DHT11_Sensor_GPIO_Port, DHT11_Sensor_Pin, SET);
	timer_usDelay(30);

	gpio_setPinInput(hw_pins->dht11_port, hw_pins->dht11_pin);
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











