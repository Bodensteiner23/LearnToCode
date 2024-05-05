/*****
 *	modul: gpio.c
 *
 *	created on: 03.05.2024
 *	author: Matthias Bodensteiner
 *****/
#include "gpio.h"
#include <stdint.h>



void gpio_setPinInput(GPIO_TypeDef *_port, uint16_t _pin) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
}


void gpio_setPinOutput(GPIO_TypeDef *_port, uint16_t _pin) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
}






