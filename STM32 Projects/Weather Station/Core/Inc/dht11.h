/*****
 *	modul: dht11.h
 *
 *	created on: 29.04.2024
 *	author: Matthias Bodensteiner
 *****/

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include <stdbool.h>

void dht11_readoutSensor(void);

void dht11_initCommunication(void);

bool dht11_checkResponse(void);

void dht11_readBit(void);


#endif /* INC_DHT11_H_ */
