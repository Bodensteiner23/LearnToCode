#include <functional>
#include <iostream>
#include <optional>
#include <vector>

class SignalBase {
public:
  virtual ~SignalBase() = default;
};

template<typename T>
class Signal : public SignalBase {
public:
  Signal() = default;
  ~Signal() override = default;
  T getValue();
  typedef T value_type;
};
using AnalogSignal = Signal<float>;
template<>
float Signal<float>::getValue() {
  return 0.5f; // Placeholder for actual signal value
}

using DigitalSignal = Signal<bool>;
template<>
bool Signal<bool>::getValue() {
  return true; // Placeholder for actual signal value
}

template<typename T>
concept IsSignal = std::is_base_of_v<Signal<typename T::value_type>, T>;

class SlotBase {
public:
  virtual ~SlotBase() = default;
};

template<IsSignal T>
class Slot : public SlotBase {
  std::optional<T *> value;

public:
  using ValueType = typename T::value_type;

  Slot() : value(std::nullopt) {}
  ~Slot() override = default;
  void set(T &val) { value = &val; }
  ValueType getValue() {
   if (value)
    return (*value)->getValue();
   return ValueType();
  }
};


class LevelSensor {
public:
  Slot<AnalogSignal> connectedSignal;
  float getLevel() { return connectedSignal.getValue() * 100.0f; }
};

class InvertedDigitalSensor {
public:
  Slot<DigitalSignal> connectedSignal;
  bool getValue() { return !connectedSignal.getValue(); }
};

class ConnectionManager {
  std::array<std::pair<SignalBase *, SlotBase *>, 20> connections;
  size_t connectionIndex = 0;

public:
  template<typename T>
  void connect(T &source, Slot<T> &destination) {
   destination.set(source);
   std::cout << "Connected signal " << &source << " to slot " << &destination << std::endl;
   connections[connectionIndex++] = {&source, &destination};
  }
  void printConnections() {
   for (auto &conn: connections) {
    std::cout << "Connection: " << conn.first << " -> " << conn.second << std::endl;
    if (auto signal = dynamic_cast<AnalogSignal *>(conn.first)) {
     std::cout << "AnalogSignal: " << signal->getValue() << std::endl;
    } else if (auto signal = dynamic_cast<DigitalSignal *>(conn.first)) {
     std::cout << "DigitalSignal: " << signal->getValue() << std::endl;
    }
   }
  }
};

class PLC {
public:
  std::array<DigitalSignal, 16> digitalInputs;
  std::array<AnalogSignal, 6> analogInputs;

  std::array<Slot<DigitalSignal>, 14> digitalOutputs;
  std::array<Slot<AnalogSignal>, 2> analogOutputs;
};

int main() {
  PLC p;
  LevelSensor level;
  InvertedDigitalSensor inverted_digital_sensor;
  ConnectionManager connectionManager;

  connectionManager.connect(p.analogInputs[0], level.connectedSignal);
  connectionManager.connect(p.digitalInputs[0], inverted_digital_sensor.connectedSignal);

  connectionManager.connect(p.digitalInputs[14], p.digitalOutputs[14]);
  connectionManager.connect(p.digitalInputs[15], p.digitalOutputs[15]);
  connectionManager.printConnections();

  std::cout << "Level: " << level.getLevel() << std::endl;
  std::cout << "Inverted Digital Sensor Value: " << inverted_digital_sensor.getValue() << std::endl;
  return 0;
}