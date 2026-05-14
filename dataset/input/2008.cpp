#include <iostream>

class Printer {
public:
    void print(int value) {
        std::cout << "Integer: " << value << std::endl;
    }

    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    void print(const char* value) {
        std::cout << "String: " << value << std::endl
    } // Syntax Error: Missing semicolon here
};

int main() {
    Printer p;
    p.print(10);
    p.print(3.14);
    p.print("Hello C++");
    return 0;
}