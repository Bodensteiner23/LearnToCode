/*****
 * 	created on: 03.05.2024
 * 	author: Matthias Bodensteiner
 *
 * 					##### How to use this module #####
 *	========================================================================
 * 	Configuration in CubeMX:
 * 		1. Go to the USART you want to use and enable it.
 * 		2. Set Baudrate to 115200 (should be standard).
 * 		3. Go to NVIC Settings for the UART and activate Interrupts.
 *
 *	Usage:
 *		- Call uart_initUart Function in main.c and handover UART_HandleTypeDef
 *		of the uart you want to use for debug.
 *		- To send Data via Uart use this sample code:
 *
 *		char buffer[100];
 *		uart_sendUartDebugData(buffer, 100, "Debug Text: %d \n\r, debug_variable);
 *
 * 		- Declare a buffer with the char size you need. 100 should be enough.
 * 		After that you can receive Data with an Logic Analyzer or with e.g Putty.
 *****/

#include "uart.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm32f4xx_hal.h>

UART_HandleTypeDef hhuart1;

void uart_initUart(UART_HandleTypeDef _huart) {
	hhuart1 = _huart;
}

void uart_sendUartDebugData(char* _buffer, size_t _buffer_size, char* _debug_text,
		int16_t _debug_variable) {
	snprintf(_buffer, _buffer_size, _debug_text, (int) _debug_variable);
	HAL_UART_Transmit_IT(&hhuart1, (uint8_t*) _buffer, strlen(_buffer));
}
