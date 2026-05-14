#include <iostream>
#include <sstream>
#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getters for private members (needed for stream operator and demonstration)
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Robustness Issue: This operator+ modifies the current object (*this)
    // instead of returning a new ComplexNumber representing the sum.
    // This violates the expected behavior of a binary addition operator,
    // which should not modify its operands.
    ComplexNumber operator+(const ComplexNumber& other) {
        this->real += other.real;       // Modifies 'this->real'
        this->imaginary += other.imaginary; // Modifies 'this->imaginary'
        return *this; // Returns the modified current object
    }
};

// Stream insertion operator for easy printing
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.getReal() << " + " << c.getImaginary() << "i";
    return os;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        double r1, i1, r2, i2;
        if (!(iss >> r1 >> i1 >> r2 >> i2)) {
            std::cerr << "Invalid input format. Please enter four doubles." << std::endl;
            continue;
        }

        ComplexNumber c1(r1, i1);
        ComplexNumber c2(r2, i2);

        // Performing addition
        ComplexNumber sum = c1 + c2;

        // The robustness issue will be evident here:
        // c1 will be modified to become the sum, which is incorrect behavior for operator+
        // For example, if c1=(1,2) and c2=(3,4), after sum = c1 + c2, c1 will be (4,6)
        // while it should remain (1,2).
        std::cout << sum << std::endl;
    }
    return 0;
}