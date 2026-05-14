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

    // Readability / Efficiency Issue:
    // 1. operator+ is a member function, which is less symmetric for binary operators
    //    compared to a non-member friend function.
    // 2. The 'other' Complex object is passed by value, leading to an unnecessary copy
    //    of 'other'. For a class with just two doubles, the performance impact is minor,
    //    but it's an inefficient practice for larger objects.
    Complex operator+(Complex other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
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
    Complex sum1 = c1 + c2;
    Complex sum2 = c3 + c4;
    Complex sum3 = c1 + c3;

    // Print results
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << sum1 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c3 + c4: " << sum2 << std::endl;
    std::cout << "c1 + c3: " << sum3 << std::endl;

    return 0;
}