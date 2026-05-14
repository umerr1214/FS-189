#include <iostream>

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Constructor with default values for real and imaginary parts.
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Overload the addition operator.
    // Declared 'const' as it does not modify the current object.
    // Returns a new ComplexNumber object representing the sum.
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // Overload the stream insertion operator to enable easy printing.
    // Declared as a friend function to access private members (if they were private)
    // and to allow `std::cout << complex_obj;` syntax.
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.real;
        if (c.imaginary >= 0) {
            os << " + " << c.imaginary << "i";
        } else {
            os << " - " << -c.imaginary << "i";
        }
        return os;
    }
};

int main() {
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber c2(1.5, -2.5);
    ComplexNumber c3 = c1 + c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;

    ComplexNumber c4(0.5, 1.0);
    ComplexNumber c5(-2.0, 0.0);
    ComplexNumber c6 = c4 + c5;
    std::cout << "c4 + c5: " << c6 << std::endl;

    // Test with default constructor and zero values
    ComplexNumber zero_c; // 0 + 0i
    ComplexNumber five_plus_zero(5.0); // 5 + 0i
    ComplexNumber result_zero = zero_c + five_plus_zero;
    std::cout << "0 + 5: " << result_zero << std::endl;

    // Test with const objects (works due to const-correctness of operator+)
    const ComplexNumber const_c1(1.0, 1.0);
    const ComplexNumber const_c2(2.0, 2.0);
    ComplexNumber const_sum = const_c1 + const_c2;
    std::cout << "const_c1 + const_c2: " << const_sum << std::endl;

    return 0;
}