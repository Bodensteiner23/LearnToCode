/*****
 *	modul: dht11.h
 *
 *	created on: 29.04.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include <stdbool.h>
#include <stdint.h>

void dht11_readoutSensor(void);

void dht11_initCommunication(void);

bool dht11_checkResponse(void);

uint8_t dht11_readBit(void);

void dht11_readData(void);

#endif /* INC_DHT11_H_ */
