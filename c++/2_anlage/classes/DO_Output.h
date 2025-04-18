#pragma once
#include <stdbool.h>
#include <string>

class DO_Output {
private:
    bool output_state;
    std::string output_name;     // X11_1, X11_2 ...
    // Oder einfach ID von jeder Nachricht hinzufügen statt name / Zusätzlich?
public:
    DO_Output(const std::string& name) : input_name(name), output_state(false){}
    bool set_value(){
        // Hier wird in Tabelle geschrieben?
    }
};