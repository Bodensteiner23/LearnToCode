#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stm32f4xx_hal.h>

typedef struct {
	GPIO_TypeDef *dht11_port;
	uint16_t dht11_pin;
} gpio_t;



#endif /* INC_GPIO_H_ */
