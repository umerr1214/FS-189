#include <iostream>
#include <string> // Included for general C++ string context, though not strictly used for const char* value directly in problematic function.

class Printer {
public:
    void print(int value) {
        std::cout << "Integer: " << value << std::endl;
    }

    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    // Robustness Issue: This function does not handle nullptr input for 'value'.
    // Dereferencing or printing a nullptr const char* results in undefined behavior,
    // which can lead to crashes or unexpected output.
    void print(const char* value) {
        std::cout << "String: " << value << std::endl;
    }
};

int main() {
    // This main is for local compilation/testing. The JSON driver will be used for evaluation.
    // The JSON driver will call p.print(static_cast<const char*>(nullptr)); to trigger the issue.
    Printer p;
    p.print(10);
    p.print(3.14);
    p.print("Hello Robustness");
    // The following line would trigger the robustness issue if uncommented
    // p.print(static_cast<const char*>(nullptr));
    return 0;
}