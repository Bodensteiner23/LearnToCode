#include "dht11.h"
#include "Arduino.h"


bool DHT11::init_communication() {
    digitalWrite(sensor_pin, LOW);
    delay(20);
    digitalWrite(sensor_pin, HIGH);
    delayMicroseconds(80);
    if (digitalRead(sensor_pin) == LOW) {
        delayMicroseconds(80);
        if (digitalRead(sensor_pin) == HIGH) {
            return true;
        }
    }
    return false;
}


bool DHT11::read_data() {
    if (!DHT11::init_communication()) {
        // No communication
        return false;
    }

    for (uint8_t i = 0; i < 40; i++) {
        while (digitalRead(sensor_pin) != LOW) {
            // Wait until transmission starting
            // ToDo: Add timer to avoid endless loop. Also return false if that timer elapsed
        }

        delayMicroseconds(100);
        if (digitalRead(sensor_pin) == HIGH) {
            DHT11::data[i] = 1;
        } else {
            DHT11::data[i] = 0;
        }
    }

    return true;
}


float DHT11::get_humid() {
    int humid_int = 0;
    int humid_dec = 0;

    for (uint8_t i = 0; i < 8; i++) {
        humid_int |= (data[i] & 1) << i;
    }
    for (uint8_t i = 8; i < 16; i++) {
        humid_dec |= (data[i] & 1) << (i % 8);
    }

    float humid = humid_int + (humid_dec / 100);

    return humid;
}


float DHT11::get_temp() {
    int temp_int = 0;
    int temp_dec = 0;

    for (uint8_t i = 17; i < 24; i++) {
        temp_int |= (data[i] & 1) << (i % 8);
    }
    for (uint8_t i = 24; i < 32; i++) {
        temp_dec |= (data[i] & 1) << (i % 8);
    }

    float temp = temp_int + (temp_dec / 100);

    return temp;
}



