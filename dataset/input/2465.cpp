#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        // LOGICAL ERROR: Subtracting imaginary parts instead of adding them
        return ComplexNumber(real + other.real, imaginary - other.imaginary);
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& obj) {
        os << obj.real;
        if (obj.imaginary >= 0) {
            os << " + " << obj.imaginary << "i";
        } else {
            os << " - " << -obj.imaginary << "i";
        }
        return os;
    }
};

int main() {
    ComplexNumber c1(3.0, 2.0);
    ComplexNumber c2(1.0, 7.0);
    ComplexNumber c3 = c1 + c2; // Expected: 4 + 9i, Actual: 4 - 5i
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;

    ComplexNumber c4(5.0, -3.0);
    ComplexNumber c5(2.0, 1.0);
    ComplexNumber c6 = c4 + c5; // Expected: 7 - 2i, Actual: 7 - 4i
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c4 + c5: " << c6 << std::endl;

    return 0;
}