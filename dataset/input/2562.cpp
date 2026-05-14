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

    // Semantic Error: The binary + operator should return a new object
    // without modifying its operands. Here, it modifies 'this' object.
    ComplexNumber operator+(const ComplexNumber& other) { // Not const, as it modifies 'this'
        this->real += other.real;
        this->imaginary += other.imaginary;
        return *this; // Returns the modified *this
    }
};

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3 = c1 + c2; // This line modifies c1 to (4.0, 6.0)
    std::cout << "c1: "; c1.display(); std::cout << std::endl; // c1 is now (4.0, 6.0)
    std::cout << "c2: "; c2.display(); std::cout << std::endl;
    std::cout << "c1 + c2: "; c3.display(); std::cout << std::endl; // c3 is also (4.0, 6.0)

    ComplexNumber c4(0.5, -1.5);
    ComplexNumber c5(-2.0, 3.0);
    ComplexNumber c6 = c4 + c5; // This line modifies c4 to (-1.5, 1.5)
    std::cout << "c4: "; c4.display(); std::cout << std::endl; // c4 is now (-1.5, 1.5)
    std::cout << "c5: "; c5.display(); std::cout << std::endl;
    std::cout << "c4 + c5: "; c6.display(); std::cout << std::endl;

    return 0;
}