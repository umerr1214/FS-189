#include <iostream>
#include <string>

class Printer {
public:
    void print(std::string value) {
        // Syntax Error: Missing std:: qualifier for cout
        cout << "String: " << value << std::endl;
    }
    void print(int value) {
        std::cout << "Int: " << value << std::endl;
    }
    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }
    void print(bool value) {
        std::cout << "Bool: " << (value ? "true" : "false") << std::endl;
    }
};

int main() {
    Printer p;
    p.print("Hello, C++");
    p.print(123);
    p.print(3.14159);
    p.print(true);
    return 0;
}