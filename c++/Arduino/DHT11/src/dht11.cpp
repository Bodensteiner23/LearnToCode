#include "dht11.h"


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


float DHT11::read_temp() {
    if (!DHT11::init_communication()) {
        // 
        return 1;
    }



}



