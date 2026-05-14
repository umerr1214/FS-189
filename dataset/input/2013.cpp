#include <iostream>
#include <string> // Included for general C++ string context and potential future use

class Printer {
public:
    void print(int value) {
        std::cout << "Integer: " << value << std::endl;
    }

    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    // Correct Version: Handles nullptr gracefully by checking the pointer
    // before attempting to print, ensuring robustness.
    void print(const char* value) {
        if (value == nullptr) {
            std::cout << "String: (null)" << std::endl;
        } else {
            std::cout << "String: " << value << std::endl;
        }
    }
};

int main() {
    // This main is for local compilation/testing. The JSON driver will be used for evaluation.
    Printer p;
    p.print(30);
    p.print(9.81);
    p.print("Correct Version");
    p.print(static_cast<const char*>(nullptr)); // Handled gracefully
    return 0;
}