#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

class Sensor {
private:
    uint8_t temperature;
public:
    Sensor() {
        srand(time(nullptr));
        temperature = 0;
    }
    void measure() {
        temperature = 20 + (rand() % 60);
    };
    void show_value() const {
        printf("Temperatur: %d\n", temperature);
    };
    void check_failure() const{
        if (temperature > 60) {
            printf("Temperatur zu hoch\n");
        }
    }
};


