#pragma once
#include <string>
#include <array>
#include "DI_0_24V_Input.h"

class PCB_DI {
private:
    std::array<DI_0_24V_Input, 16> inputs;
public:
    PCB_DI() : inputs{DI_0_24V_Input("Input_1"), DI_0_24V_Input("Input_2"), DI_0_24V_Input("Input_3"),
                      DI_0_24V_Input("Input_4"), DI_0_24V_Input("Input_5"), DI_0_24V_Input("Input_6"),
                      DI_0_24V_Input("Input_7"), DI_0_24V_Input("Input_8"), DI_0_24V_Input("Input_9"),
                      DI_0_24V_Input("Input_10"), DI_0_24V_Input("Input_11"), DI_0_24V_Input("Input_12"),
                      DI_0_24V_Input("Input_13"), DI_0_24V_Input("Input_14"), DI_0_24V_Input("Input_15"),
                      DI_0_24V_Input("Input_16")} {}    // 16x DI Input. Bennung anpassen

    bool get_input_value(uint8_t input_index) const{
        return inputs.at(input_index).get_value();
    }
};
