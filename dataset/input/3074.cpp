#include <iostream>
#include <string> // Needed for the inefficient string conversion

class Printer {
public:
    void print(int value) {
        // Efficiency Issue: Using std::endl flushes the buffer on each call, less efficient than '\n'.
        std::cout << "Printing an integer: " << value << std::endl;
    }

    void print(double value) {
        // Efficiency Issue: Using std::endl flushes the buffer on each call, less efficient than '\n'.
        std::cout << "Printing a double: " << value << std::endl;
    }

    // Readability/Efficiency Issue: Creates a temporary std::string from const char*
    // incurring an unnecessary memory allocation and copy.
    void print(const char* value) {
        // This is inefficient. Direct printing `std::cout << value` (with a nullptr check) is better.
        std::string temp_str = (value != nullptr) ? std::string(value) : "(null)";
        std::cout << "Printing a C-style string: " << temp_str << std::endl; // std::endl inefficiency
    }
};

int main() {
    Printer p;

    // Test cases for Readability / Efficiency Issue
    std::cout << "--- Testing Readability / Efficiency Issue ---" << std::endl;

    p.print(12345);
    p.print(98.765);
    p.print("Another string example");

    // Test with nullptr to show it's handled, but still inefficiently
    const char* null_str_test = nullptr;
    p.print(null_str_test);

    p.print("Short"); // Test short string
    p.print("A very long string that might highlight the overhead of unnecessary string conversion and allocation for C-style strings, especially if done repeatedly.");

    std::cout << "--- End Readability / Efficiency Issue Test ---" << std::endl;

    return 0;
}