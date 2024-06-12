/*****
 * 	modul: uart.c
 *
 * 	created on: 03.05.2024
 * 	author: Matthias Bodensteiner
 *
 * 					##### How to use this module #####
 *	========================================================================
 * 	Configuration in CubeMX:
 * 		1. Go to the USART you want to use and enable it.
 * 		2. Set Baudrate to 115200 (should be standard).
 *
 *	Usage:
 *		- Call uart_initUart Function in main.c and handover UART_HandleTypeDef
 *		of the uart you want to use for debug.
 *		- To send Data via Uart use this sample code:
 *
 *		uart_sendUartDebugData("Debug Text: %d \n\r, debug_variable);
 *
 * 		- Declare a buffer with the char size you need. 100 should be enough.
 * 		After that you can receive Data with an Logic Analyzer or with e.g Putty.
 *
 *
 * 		!!!!! This module is not sending via Interrupt !!!!!
 * 		If you are sending e.g. an array, your program will be stopped for the
 * 		time period until the array is fully sent via uart.
 *
 *****/
#include "uart.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

UART_HandleTypeDef *hhuart1;

void uart_initUart(UART_HandleTypeDef *_huart) {
	hhuart1 = _huart;
}

void uart_sendUartDebugData(char* _debug_text, int16_t _debug_variable) {
	char buffer[1000];
	size_t buffer_size = 1000;

	snprintf(buffer, buffer_size, _debug_text, (int) _debug_variable);
	HAL_UART_Transmit(hhuart1, (uint8_t*) buffer, strlen(buffer), HAL_MAX_DELAY);
}
