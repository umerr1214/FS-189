#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    void display() const {
        if (imaginary >= 0) {
            std::cout << real << " + " << imaginary << "i";
        } else {
            std::cout << real << " - " << -imaginary << "i";
        }
    }

    // Overload the binary + operator as a friend function
    friend ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);
};

// Logical Error: Adding real part of c1 to imaginary part of c2, and vice-versa
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    return ComplexNumber(c1.real + c2.imaginary, c1.imaginary + c2.real); // Incorrect logic
}

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3 = c1 + c2;
    std::cout << "c1: "; c1.display(); std::cout << std::endl;
    std::cout << "c2: "; c2.display(); std::cout << std::endl;
    std::cout << "c1 + c2: "; c3.display(); std::cout << std::endl;

    ComplexNumber c4(0.5, -1.5);
    ComplexNumber c5(-2.0, 3.0);
    ComplexNumber c6 = c4 + c5;
    std::cout << "c4: "; c4.display(); std::cout << std::endl;
    std::cout << "c5: "; c5.display(); std::cout << std::endl;
    std::cout << "c4 + c5: "; c6.display(); std::cout << std::endl;

    return 0;
}