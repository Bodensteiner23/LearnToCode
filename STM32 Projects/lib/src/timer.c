#include "timer.h"
#include <stdint.h>
#include <stm32f4xx_hal.h>


TIM_HandleTypeDef *hhtim1;

// ToDO: Add initTimer in main
void timer_initTimer(TIM_HandleTypeDef *_htim) {
	hhtim1 = _htim;
}


void timer_usDelay(uint16_t _us) {
	__HAL_TIM_SET_COUNTER(hhtim1, 0);
	while ((uint16_t)__HAL_TIM_GET_COUNTER(hhtim1) < _us);
}
