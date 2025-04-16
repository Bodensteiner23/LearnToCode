#include <stdint.h>
#include <thread>

#include "Sensor.h"



int main() {

    Sensor sensor;

    while (true) {
        sensor.measure();
        sensor.show_value();
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }



    return 0;
}


