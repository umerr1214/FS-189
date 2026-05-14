#include <iostream>
#include <string>

class Printer {
public:
    void print(std::string value) {
        std::cout << "String: " << value << std::endl;
    }
    void print(int value) {
        std::cout << "Int: " << value << std::endl;
    }
    void print(double value) {
        // Semantic Error: The method is intended to print the 'value' parameter (a double),
        // but it semantically misuses the parameter by ignoring it and printing an unrelated
        // private member variable 'default_int_value' instead. This violates the method's contract.
        std::cout << "Double: " << default_int_value << std::endl; // Should be 'value'
    }
    void print(bool value) {
        std::cout << "Bool: " << (value ? "true" : "false") << std::endl;
    }

private:
    int default_int_value = 0; // An irrelevant member for printing double values
};

int main() {
    Printer p;
    p.print("Hello, C++");
    p.print(123);
    p.print(3.14159); // Expected: Double: 3.14159, Actual: Double: 0
    p.print(true);
    return 0;
}