#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }
    // No friend declaration for operator<<
};

// SEMANTIC ERROR: This non-member operator<< attempts to access private members
// 'real' and 'imaginary' of ComplexNumber without being declared as a friend.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& obj) {
    os << obj.real; // Error: 'double ComplexNumber::real' is private
    if (obj.imaginary >= 0) {
        os << " + " << obj.imaginary << "i"; // Error: 'double ComplexNumber::imaginary' is private
    } else {
        os << " - " << -obj.imaginary << "i"; // Error: 'double ComplexNumber::imaginary' is private
    }
    return os;
}

int main() {
    ComplexNumber c1(3.0, 2.0);
    ComplexNumber c2(1.0, 7.0);
    ComplexNumber c3 = c1 + c2;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;

    ComplexNumber c4(5.0, -3.0);
    ComplexNumber c5(2.0, 1.0);
    ComplexNumber c6 = c4 + c5;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c4 + c5: " << c6 << std::endl;

    return 0;
}