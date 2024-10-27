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

#define MAX_TEMP_SENSOR     125
#define MIN_TEMP_SENSOR     -40
#define MAX_HUMID_SENSOR    70
#define MIN_HUMID_SENSOR    -20

/* Variables ---------------------------------------------------------------- */





/* Functions ---------------------------------------------------------------- */

int16_t sensor_createTempData(int8_t _min_temp, int8_t _max_temp) {
     
    srand(time(NULL));

    int16_t temp_data_value = rand() % _max_temp + _min_temp;   

    return temp_data_value;
}