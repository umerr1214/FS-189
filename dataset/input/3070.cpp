#include <iostream>

class Printer {
public:
    void print(int i) {
        std::cout << "Integer: " << i std::endl; // Syntax Error: Missing '<<' operator
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
    return 0;
}