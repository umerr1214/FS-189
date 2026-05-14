#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Method to display the complex number
    void display() const {
        std::cout << std::fixed << std::setprecision(1) << "(" << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i)";
        } else {
            std::cout << " - " << -imaginary << "i)";
        }
    }
}; // Missing semicolon here is the syntax error

// Overload the binary + operator for ComplexNumber objects
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    return ComplexNumber(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

// Overload the << operator for easy printing
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << std::fixed << std::setprecision(1) << "(" << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i)";
    } else {
        os << " - " << -c.imaginary << "i)";
    }
    return os;
}

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber sum = c1 + c2;
    std::cout << "Sum: " << sum << std::endl;

    ComplexNumber c3(5.0, -1.0);
    ComplexNumber c4(-2.0, 3.0);
    ComplexNumber sum2 = c3 + c4;
    std::cout << "Sum: " << sum2 << std::endl;

    return 0;
}