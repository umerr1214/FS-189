#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Correct Version:
    // Uses C++11 delegating constructors and initializer lists for optimal readability and efficiency.

    // Constructor taking both parts: uses initializer list
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Constructor taking only real part: delegates to the two-argument constructor
    Complex(double r) : Complex(r, 0.0) {}

    // Default constructor: delegates to the two-argument constructor
    Complex() : Complex(0.0, 0.0) {}

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
    std::cout << "Testing Correct Version (1905.cpp)\n";
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