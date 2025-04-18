#include <iostream>
#include <stdint.h>


/* Console -------------------------------------------- */
class Console {
public:
    void static show_calculation_menue() {
        std::cout << "--------- Calculator ---------\n";
        std::cout << "1. Sum\n";
        std::cout << "2. Diff\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n\n";
    }

    void static show_type_menu() {
        std::cout << "\nSelect data types:\n";
        std::cout << "1. int + int\n";
        std::cout << "2. double + double\n";
        std::cout << "3. float + float\n\n";
    }

    int static get_calculation_type() {
        int calculation_type = 0;
        std::cout << "Input: ", std::cin >> calculation_type, std::cout <<"\n";
        return calculation_type;
    }

    template <typename T>
    static T get_number() {
        T input_number;
        std::cout << "Input Number to calculate: ", std::cin >> input_number;
        return input_number;
    }
};

/* App -------------------------------------------- */
class App {
public:
    template <typename T, typename U>
    static auto calculate(T num1, U num2, uint8_t calculation_type) {
        switch (calculation_type) {
            case(1):
                return (num1 + num2);
            case(2):
                return (num1 - num2);
            case(3):
                return (num1 * num2);
            case(4):
                if (num2 != 0) {
                    return (num1 / num2);
                }
                break;
            default:
                std::cout << "Invalid Operation";
        }
    }

    template <typename T, typename U>
    void static run_calculation(uint8_t calculation_type) {
        Console c;
        T num1 = c.get_number<T>();
        U num2 = c.get_number<U>();

        auto result = calculate(num1, num2, calculation_type);
        std::cout << "\nResult: " << result;

    }
};


int main() {
    App a;
    Console c;

    c.show_calculation_menue();
    int calculation_type = c.get_calculation_type();
    c.show_type_menu();
    int type = c.get_calculation_type();

    switch (type) {
        case(1):
            a.run_calculation<int, int>(calculation_type);
            break;
        case(2):
            a.run_calculation<double, double>(calculation_type);
            break;
        case(3):
            a.run_calculation<float, float>(calculation_type);
            break;
        default:
            std::cout << "Invalid type";
    }

    return 0;
}
