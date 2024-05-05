/*****
 *	modul: hw_init.h
 *
 *	created on: 05.05.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_HW_INIT_H_
#define INC_HW_INIT_H_

typedef struct {
	GPIO_TypeDef *dht11_port;
	uint16_t dht11_pin;
} gpio_t;

void hw_init_pins(gpio_t *_hw_pins);

#endif /* INC_HW_INIT_H_ */
