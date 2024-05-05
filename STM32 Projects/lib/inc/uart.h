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

void debug_uart_data(char* buffer, size_t buffer_size, char* debug_text,
		int16_t debug_variable);



#endif /* INC_UART_H_ */
