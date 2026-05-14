#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Readability/Efficiency Issue:
    // All constructors use assignment in the body instead of member initializer lists.
    // While for primitive types like double this doesn't cause a significant efficiency hit
    // (no default construction + assignment overhead), it's less idiomatic C++ and can be
    // less readable, especially for complex objects where it would be inefficient.
    Complex() {
        real = 0.0;
        imaginary = 0.0;
    }

    Complex(double r) {
        real = r;
        imaginary = 0.0;
    }

    Complex(double r, double i) {
        real = r;
        imaginary = i;
    }

    void display() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }
};

// Driver code for local compilation and testing (not part of the JSON 'driver' field)
int main() {
    std::cout << "Testing Readability/Efficiency Issue (1904.cpp)\n";
    Complex c1; // Default
    Complex c2(5.5); // Real part only
    Complex c3(-2.1, 3.8); // Both parts
    Complex c4(0.0, -7.0); // Both parts, edge case

    std::cout << "c1: "; c1.display();
    std::cout << "c2: "; c2.display();
    std::cout << "c3: "; c3.display();
    std::cout << "c4: "; c4.display();

    return 0;
}