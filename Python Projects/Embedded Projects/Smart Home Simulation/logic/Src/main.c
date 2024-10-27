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

/****
 * ToDos:
 *  Sensor File:
 *  - Create Temp sensor data   -> int16_t format -> Betriebstemp. -40°C - 125°C
 *  - Create Humid sensor data  -> int16_t format -> Betriebstemp. -20°C - 70°C
 *  
 *  Application:
 *  - Glätten der Sensorwerte -> keine großen Sprünge zulassen
 *  - Mittelwert von jeweils 3 Messungen nehmen um Sprünge noch besser zu verhindern
 *  - Edge case betrachten wenn temperatur höher als humid max temp ist
 *  - 
 */

/* Includes ----------------------------------------------------------------- */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defines ------------------------------------------------------------------ */



/* Variables ---------------------------------------------------------------- */


/* Function Declarations ---------------------------------------------------- */


/* Sensor ------------------------------------------------------------------- */




/* Application -------------------------------------------------------------- */

void app_delay(int _number_of_millisecconds) {

    clock_t start_time = clock();

    while (clock() < start_time + _number_of_millisecconds);
    // ToDo: Add something with RTOS so not everything is done with just waiting. Or create your own.
} 


void app_smoothSensorData() {

}



int main(void) {

    // Wait at the beginning so the python script can start
    // app_delay(5000);

    /* Init Modules */
    sensor_initSensorModule();
    
    // ToDo: Tasks anyhow
    for(;;) {

        // Read sensor values
        int16_t temp_data   = sensor_createTempData(20, 40);
        int16_t humid_data  = sensor_createHumidData(40, 60);
        printf("Temp Value: %i\n", temp_data);
        printf("Humid Value: %i\n", humid_data);

        app_delay(1000);


    }
    
    return 0;
}