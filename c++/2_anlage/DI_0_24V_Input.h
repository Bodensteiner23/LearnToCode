#pragma once
#include <stdbool.h>
#include <string>

class DI_0_24V_Input {
private:
    bool input_state;
    std::string input_name;     // X11_1, X11_2 ...
    // ID von jeder Nachricht hinzufügen?
public:
    DI_0_24V_Input(const std::string& name) : input_name(name), input_state(false){}
    bool get_value() const{
        return input_state;
    }
};