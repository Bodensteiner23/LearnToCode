#pragma once
#include <array>
#include "PCB_DI.h"



class Koffertool {
private:
    std::array<PCB_DI, 4> DI_PCBs;

public:
    Koffertool() = default;

    const PCB_DI& getDigitalInputPCB(int index) {
        if (index >= 0 && index < DI_PCBs.size()) {
            return DI_PCBs[index];
        }
        throw std::out_of_range("Index out of range");
    }
};