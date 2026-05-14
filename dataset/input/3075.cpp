#include <iostream> // For std::cout

class Printer {
public:
    // Overloaded method to print an integer
    void print(int value) {
        std::cout << "Printing an integer: " << value << '\n';
    }

    // Overloaded method to print a double
    void print(double value) {
        std::cout << "Printing a double: " << value << '\n';
    }

    // Overloaded method to print a C-style string (const char*)
    // Handles nullptr robustly and efficiently by printing "(null)".
    void print(const char* value) {
        if (value == nullptr) {
            std::cout << "Printing a C-style string: (null)\n";
        } else {
            std::cout << "Printing a C-style string: " << value << '\n';
        }
    }
};

int main() {
    Printer p;

    // Demonstrate printing different data types using the same method name
    std::cout << "--- Testing Correct Version ---" << '\n';

    // 1. Print an integer
    p.print(123456);

    // 2. Print a double
    p.print(789.01234);

    // 3. Print a C-style string
    p.print("This is a C-style string.");

    // Demonstrate nullptr handling for C-style string
    const char* null_string = nullptr;
    p.print(null_string);

    // Demonstrate empty string handling
    p.print("");

    // Another integer
    p.print(0);

    // Another double
    p.print(-1.23);

    std::cout << "--- End Correct Version Test ---" << '\n';

    return 0;
}