#include <iostream>
#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << cn.real;
    // Logical Error: Always prints '+' before the imaginary part,
    // even if the imaginary part is negative. This results in "real + -imaginaryi"
    // instead of the desired "real - |imaginary|i".
    if (cn.imaginary != 0.0) {
        os << " + " << cn.imaginary << "i";
    } else { // Handle 0.0 imaginary to match format "real + 0.0i"
        os << " + 0.0i";
    }
    return os;
}

int main() {
    ComplexNumber c1(3.0, 4.5);
    ComplexNumber c2(2.0, -1.5); // Expected: 2.0 - 1.5i, Actual: 2.0 + -1.5i
    ComplexNumber c3(0.0, 7.0);
    ComplexNumber c4(5.0, 0.0);
    ComplexNumber c5(-1.0, -2.0); // Expected: -1.0 - 2.0i, Actual: -1.0 + -2.0i
    ComplexNumber c6(0.0, 0.0);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c6: " << c6 << std::endl;

    return 0;
}