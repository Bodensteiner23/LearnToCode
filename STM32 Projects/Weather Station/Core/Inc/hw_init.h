/*
 * hw_init.h
 *
 *  Created on: May 5, 2024
 *      Author: boden
 */

#ifndef INC_HW_INIT_H_
#define INC_HW_INIT_H_

typedef struct {
	GPIO_TypeDef *dht11_port;
	uint16_t dht11_pin;
} gpio_t;

void hw_init_pins(gpio_t *_hw_pins);

#endif /* INC_HW_INIT_H_ */
