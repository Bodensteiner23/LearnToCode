#pragma once
#include "Arduino.h"



class DHT11 {
private:
    uint8_t sensor_pin;
    bool init_communication();

public:
    explicit DHT11 (const uint8_t pin) : sensor_pin(pin) {};   // ToDo: Check what is explicit

    float read_temp();
    float read_humid();

};



