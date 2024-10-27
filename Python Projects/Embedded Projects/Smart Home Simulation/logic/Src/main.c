/**
 * @file    main.c
 * @author  Matthias Bodensteiner
 * @brief   Module, that implements the simulation of a weather station.
 * @version 1.0
 * @date    28.10.2024
 * 
 * =============================================================================
 *                          ### Project Description ###
 * =============================================================================
 * 
 *  Simulating weather station containing temperature sensor and humid sensor.
 *  Depending on this sensor data, the house that the weather station is 
 *  managing, should turn on and off the heating.
 * 
 *  In the end data shoud be plotted with an python script.
 * 
 */

/* Includes ----------------------------------------------------------------- */

#include "sensor.h"
#include <stdint.h>
#include <stdio.h>

/* Defines ------------------------------------------------------------------ */


/* Variables ---------------------------------------------------------------- */




/* Functions ---------------------------------------------------------------- */

int main(void) {

    int16_t value = sensor_createTempData(0, 80);

    printf("Value: %i", value);
    printf("Test23");
    
    return 0;
}