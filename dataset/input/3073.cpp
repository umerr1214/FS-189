#include <iostream>

class Printer {
public:
    void print(int value) {
        std::cout << "Printing an integer: " << value << std::endl;
    }

    void print(double value) {
        std::cout << "Printing a double: " << value << std::endl;
    }

    // Robustness Issue: This method does not explicitly handle nullptr for C-style strings.
    // std::cout will typically print "0x0" or "(nil)" for a nullptr,
    // which is not a crash but also not a user-friendly representation like "(null)".
    void print(const char* value) {
        std::cout << "Printing a C-style string: " << value << std::endl;
    }
};

int main() {
    Printer p;

    // Test cases for Robustness Issue
    std::cout << "--- Testing Robustness Issue ---" << std::endl;

    // Standard cases
    p.print(123);
    p.print(45.67);
    p.print("Hello C++");

    // Edge case for robustness: nullptr C-style string
    // The output will likely be "0x0", "(nil)", or similar instead of a more descriptive "(null)".
    const char* null_str = nullptr;
    p.print(null_str);

    // Another edge case: empty string
    p.print("");

    std::cout << "--- End Robustness Issue Test ---" << std::endl;

    return 0;
}