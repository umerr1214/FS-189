#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Robustness Issue:
    // Default constructor does not initialize 'real' and 'imaginary'.
    // These members will have indeterminate values, leading to undefined behavior when accessed.
    Complex() {}

    // Constructor taking only real part:
    // 'imaginary' is not initialized, leading to indeterminate value and undefined behavior.
    Complex(double r) {
        real = r;
    }

    // Constructor taking both parts: correctly initializes both members.
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
    std::cout << "Testing Robustness Issue (1903.cpp)\n";
    Complex c1; // Default - real and imaginary uninitialized
    Complex c2(5.5); // Real part only - imaginary uninitialized
    Complex c3(-2.1, 3.8); // Both parts - correctly initialized
    Complex c4(0.0, -7.0); // Both parts, edge case - correctly initialized

    std::cout << "c1: "; c1.display(); // Accesses uninitialized members
    std::cout << "c2: "; c2.display(); // Accesses uninitialized 'imaginary'
    std::cout << "c3: "; c3.display();
    std::cout << "c4: "; c4.display();

    return 0;
}