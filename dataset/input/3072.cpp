#include <iostream>

class Printer {
public:
    void print(int i) {
        std::cout << "Integer: " << i << std::endl;
    }

private: // Semantic Error: Making print(double) private
    void print(double d) {
        std::cout << "Double: " << d << std::endl;
    }

public:
    void print(const char* s) {
        std::cout << "String: " << s << std::endl;
    }
};

int main() {
    Printer printer;
    printer.print(10);
    printer.print(3.14); // Semantic Error: Attempting to call a private method
    printer.print("Hello, C++");
    return 0;
}