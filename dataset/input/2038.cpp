#include <iostream>
#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
} // Syntax Error: Missing semicolon after class definition

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << cn.real;
    if (cn.imaginary >= 0) {
        os << " + " << cn.imaginary << "i";
    } else {
        os << " - " << -cn.imaginary << "i";
    }
    return os;
}

int main() {
    ComplexNumber c1(3.0, 4.5);
    ComplexNumber c2(2.0, -1.5);
    ComplexNumber c3(0.0, 7.0);
    ComplexNumber c4(5.0, 0.0);
    ComplexNumber c5(-1.0, -2.0);
    ComplexNumber c6(0.0, 0.0);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c6: " << c6 << std::endl;

    return 0;
}