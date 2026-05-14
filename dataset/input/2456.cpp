#include <iostream>
#include <string>
#include <iomanip> // For std::endl, std::fixed, std::setprecision, std::boolalpha

class Printer {
public:
    // Efficiency Issue: std::string passed by value, causing an unnecessary copy.
    void print(std::string s) {
        std::cout << "String: " << s << std::endl; // Efficiency Issue: uses std::endl which flushes the buffer.
    }

    void print(int i) {
        std::cout << "Int: " << i << std::endl; // Efficiency Issue: uses std::endl.
    }

    // Readability/Efficiency Issue: Unnecessary fixed precision and setprecision for double.
    // This makes the output less flexible and adds minor overhead.
    void print(double d) {
        std::cout << std::fixed << std::setprecision(2) << "Double: " << d << std::endl; // Efficiency Issue: uses std::endl.
    }

    void print(bool b) {
        std::cout << std::boolalpha << "Bool: " << b << std::endl; // Efficiency Issue: uses std::endl.
    }
};

int main() {
    Printer p;
    p.print("Hello, C++!");
    p.print(123);
    p.print(45.6789);
    p.print(true);
    p.print("");
    p.print(-5);
    p.print(0.0);
    p.print(false);
    return 0;
}