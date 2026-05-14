#include <iostream>
#include <sstream>
#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor with default arguments for real and imaginary parts
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Constant getter methods for accessing private members
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overload the + operator as a const member function
    // It returns a new ComplexNumber object representing the sum,
    // without modifying the operands.
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }
};

// Global stream insertion operator for easy and standard printing of ComplexNumber objects
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
            std::cerr << "Invalid input format. Please enter four doubles (real1 imag1 real2 imag2)." << std::endl;
            continue;
        }

        ComplexNumber c1(r1, i1);
        ComplexNumber c2(r2, i2);

        ComplexNumber sum = c1 + c2;

        std::cout << sum << std::endl;
    }
    return 0;
}