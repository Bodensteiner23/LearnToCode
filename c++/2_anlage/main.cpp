#include <iostream>

enum SignalTypes {
  Analog_Input_4_20mA,
  Digital_Input_Bool,
  Digital_Output_Bool,
  Digital_Output_DAC
};

enum PCBTypes {
  AI,
  DI,
  DO
};

template<SignalTypes T>
class Signal {
  // Private or Public?
  SignalTypes signal_type = T;
public:
  std::string signal_name;
};


template<PCBTypes T>
class PCB {
  PCBTypes pcb_type = T;
  std::unordered_map<std::string, Signal<Analog_Input_4_20mA>> analog_signals;
public:

};


int main() {





  return 0;
}