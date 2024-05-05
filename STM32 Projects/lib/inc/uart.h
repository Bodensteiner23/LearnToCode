/*****
 *	modul: uart.h
 *
 *	created on: 03.05.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_UART_H_
#define INC_UART_H_

#include <stdint.h>
#include <stddef.h>
#include <stm32f4xx_hal.h>

void uart_initUart(UART_HandleTypeDef *_huart);

void uart_sendUartDebugData(char* _buffer, size_t _buffer_size, char* _debug_text,
		int16_t _debug_variable);



#endif /* INC_UART_H_ */
