/**
 * @file    sensor.h
 * @author  Matthias Bodensteiner
 * @brief   Module, that implements simulation of sensors
 * @version 1.0
 * @date    27.10.2024
 * 
 */

#ifndef SENSOR_H
#define SENSOR_H

/* Includes ----------------------------------------------------------------- */

#include <stdint.h>


/* Functions ---------------------------------------------------------------- */

void sensor_initSensorModule(void);
int16_t sensor_createTempData(int8_t _min_temp, int8_t _max_temp);
int16_t sensor_createHumidData(int8_t _max_humid, int8_t _min_humid);


#endif // SENSOR_H