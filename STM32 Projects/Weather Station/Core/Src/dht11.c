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
#include <stdbool.h>

gpio_t *hw_pins;

// Handover HW struct
void hw_init_pins(gpio_t *_hw_pins) {
	hw_pins = _hw_pins;
}


void dht11_readoutSensor(void) {
	dht11_initCommunication();

	if (dht11_checkResponse()) {
		dht11_readBit();
	}


}

void dht11_initCommunication(void) {

	gpio_setPinOutput(hw_pins->dht11_port, hw_pins->dht11_pin);
	HAL_GPIO_WritePin(hw_pins->dht11_port, hw_pins->dht11_pin, SET);

	HAL_GPIO_WritePin(hw_pins->dht11_port, hw_pins->dht11_pin, RESET);
	timer_usDelay(18000);
	HAL_GPIO_WritePin(hw_pins->dht11_port, hw_pins->dht11_pin, SET);
	timer_usDelay(30);

	// Now sensor is pulling line LOW
	gpio_setPinInput(hw_pins->dht11_port, hw_pins->dht11_pin);
}


bool dht11_checkResponse(void) {
	timer_usDelay(30);
	// Check if Pin is LOW
	if (!(HAL_GPIO_ReadPin(hw_pins->dht11_port, hw_pins->dht11_pin))) {
		timer_usDelay(70);
		// Check if Pin is HIGH
		if (HAL_GPIO_ReadPin(hw_pins->dht11_port, hw_pins->dht11_pin)) {
			// Sensor response successful
			return true;
		}
	}
	return false;
}


void dht11_readBit(void) {
	// Wait until Pin is LOW
	while (HAL_GPIO_ReadPin(hw_pins->dht11_port, hw_pins->dht11_pin));

	// Pin is LOW


}













