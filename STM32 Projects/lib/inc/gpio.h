/*****
 *	modul: gpio.h
 *
 *	created on: 03.05.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stm32f4xx_hal.h>



void gpio_setPinInput(GPIO_TypeDef *_port, uint16_t _pin);
void gpio_setPinOutput(GPIO_TypeDef *_port, uint16_t _pin);


#endif /* INC_GPIO_H_ */
