/**
 * @file    sensor.c
 * @author  Matthias Bodensteiner
 * @brief   Module, that implements simulation of sensors
 * @version 1.0
 * @date    27.10.2024
 * 
 */

/****
 * ToDos:
 *  - Create Temp sensor data   -> int16_t format -> Betriebstemp. -40°C - 125°C
 *  - Create Humid sensor data  -> int16_t format -> Betriebstemp. -20°C - 70°C
 *  - Edge case betrachten wenn temperatur höher als humid max temp ist
 */

/* Includes ----------------------------------------------------------------- */

#include "sensor.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defines ------------------------------------------------------------------ */

/**
 *  @brief  Maximal and minimal values of temperature sensor 
 */
#define MAX_TEMP_SENSOR_VALUE   125     // in °C
#define MIN_TEMP_SENSOR_VALUE   -40     // in °C

/**
 *  @brief  Maximal and minimal values of humidity sensor
 */
#define MAX_HUMID_SENSOR_VALUE  70      // in %
#define MIN_HUMID_SENSOR_VALUE  -20     // in %

/* Variables ---------------------------------------------------------------- */





/* Functions ---------------------------------------------------------------- */

void sensor_initSensorModule(void) {
    srand(time(NULL));

}

int16_t sensor_createTempData(int8_t _min_temp, int8_t _max_temp) {
    
    if (_min_temp < MIN_TEMP_SENSOR_VALUE) {
        _min_temp = MIN_TEMP_SENSOR_VALUE;
    } else if (_max_temp > MAX_TEMP_SENSOR_VALUE) {
        _max_temp = MAX_TEMP_SENSOR_VALUE;
    }

    int16_t temp_data_value = rand() % (_max_temp - _min_temp + 1) + _min_temp;

    return temp_data_value;
}

int16_t sensor_createHumidData(int8_t _max_humid, int8_t _min_humid) {

    if (_min_humid < MIN_HUMID_SENSOR_VALUE) {
        _min_humid = MIN_HUMID_SENSOR_VALUE;
    } else if (_max_humid > MAX_HUMID_SENSOR_VALUE) {
        _max_humid = MAX_HUMID_SENSOR_VALUE;
    }

    int16_t humid_data_value = rand() % (_max_humid+ - _min_humid + 1) + _min_humid;

    return humid_data_value;
}