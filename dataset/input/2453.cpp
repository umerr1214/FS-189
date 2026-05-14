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
        std::cout << "Double: " << value << std::endl;
    }
    void print(bool value) {
        // Logical Error: This method always prints "false" regardless of the input boolean value.
        std::cout << "Bool: false" << std::endl;
    }
};

int main() {
    Printer p;
    p.print("Hello, C++");
    p.print(123);
    p.print(3.14159);
    p.print(true); // Should print "Bool: true", but will print "Bool: false"
    p.print(false); // Correctly prints "Bool: false"
    return 0;
}