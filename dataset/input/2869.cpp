#include <iostream>
#include <string>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getters
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Robustness Issue: operator+ returns a reference to a local temporary object.
    // This leads to undefined behavior once the temporary goes out of scope.
    Complex& operator+(const Complex& other) {
        Complex temp(real + other.real, imaginary + other.imaginary);
        // Returning a reference to a stack-allocated object 'temp'
        // which will be destroyed when the function returns.
        return temp;
    }

    // Friend function to overload the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real;
        if (c.imaginary >= 0) {
            os << " + " << c.imaginary << "i)";
        } else {
            os << " - " << -c.imaginary << "i)";
        }
        return os;
    }
};

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.5, -4.0);
    Complex c3(0.0, 0.0);
    Complex c4(-1.0, -1.0);

    // Perform additions
    Complex sum1 = c1 + c2; // Undefined behavior here: sum1 will point to garbage
    Complex sum2 = c3 + c4; // Undefined behavior here
    Complex sum3 = c1 + c3; // Undefined behavior here

    // Print results
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << sum1 << std::endl; // Output will be garbage
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c3 + c4: " << sum2 << std::endl; // Output will be garbage
    std::cout << "c1 + c3: " << sum3 << std::endl; // Output will be garbage

    return 0;
}