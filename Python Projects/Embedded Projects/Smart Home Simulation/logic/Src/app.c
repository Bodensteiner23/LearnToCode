/**
 * @file    app.c
 * @author  Matthias Bodensteiner
 * @brief   Module, that implements the application of the smart home simulation
 * @version 1.0
 * @date    27.10.2024
 * 
 */

/* Includes ----------------------------------------------------------------- */

#include <time.h>



/* Functions ---------------------------------------------------------------- */

void app_delay(int _number_of_millisecconds) {

    clock_t start_time = clock();

    while (clock() < start_time + _number_of_millisecconds);
    // ToDo: Add something with RTOS so not everything is done with just waiting. Or create your own.
} 


// void app_smoothSensorData() {

// }