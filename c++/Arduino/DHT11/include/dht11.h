#pragma once
#include "stdint.h"


class DHT11 {
private:
    uint8_t sensor_pin;
    uint8_t data[40];

    bool init_communication();

public:
    explicit DHT11 (const uint8_t pin) : sensor_pin(pin) {
        for (uint8_t i = 0; i < 40; i++) {
            data[i] = 0;
        }
    };   // ToDo: Check what is explicit

    bool read_data();
    float get_temp();
    float get_humid();

};



