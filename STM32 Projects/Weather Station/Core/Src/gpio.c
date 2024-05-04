#include "gpio.h"
#include <stdint.h>


gpio_t *hw_pins;

void gpio_initPins(gpio_t *_hw_pins) {
	hw_pins = _hw_pins;
}

void gpio_setPinInput(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = hw_pins->dht11_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(hw_pins->dht11_port, &GPIO_InitStruct);
}






