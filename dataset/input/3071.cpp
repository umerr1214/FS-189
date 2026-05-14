#include <iostream>

class Printer {
public:
    void print(int i) {
        // Logical Error: Prints a fixed message instead of the actual integer value
        std::cout << "An integer value was passed." << std::endl;
    }

    void print(double d) {
        std::cout << "Double: " << d << std::endl;
    }

    void print(const char* s) {
        std::cout << "String: " << s << std::endl;
    }
};

int main() {
    Printer printer;
    printer.print(10);
    printer.print(3.14);
    printer.print("Hello, C++");
    printer.print(25); // Another integer to test
    return 0;
}