/*****
 *	modul: timer.h
 *
 *	created on: 03.05.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>
#include <stm32f4xx_hal.h>

void timer_initTimer(TIM_HandleTypeDef *_htim);

void timer_usDelay(uint16_t _us);


#endif /* INC_TIMER_H_ */
