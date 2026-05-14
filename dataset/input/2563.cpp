#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Public getters for real and imaginary parts
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Overload the binary + operator as a member function
    // ROBUSTNESS ISSUE: This operator modifies *this (the left-hand operand)
    // instead of returning a new ComplexNumber representing the sum.
    ComplexNumber operator+(const ComplexNumber& other) {
        this->real += other.real;        // Modifies current object's real part
        this->imaginary += other.imaginary; // Modifies current object's imaginary part
        return *this; // Returns a copy of the modified current object
    }
};

// Overload the << operator for easy printing of ComplexNumber objects
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << std::fixed << std::setprecision(1); // Set precision for output
    os << c.getReal();
    if (c.getImaginary() >= 0) {
        os << " + " << c.getImaginary() << "i";
    } else {
        os << " - " << -c.getImaginary() << "i";
    }
    return os;
}

int main() {
    double r1, i1, r2, i2;

    // Read the first complex number from standard input
    if (!(std::cin >> r1 >> i1)) {
        std::cerr << "Invalid input for first complex number." << std::endl;
        return 1;
    }

    // Read the second complex number from standard input
    if (!(std::cin >> r2 >> i2)) {
        std::cerr << "Invalid input for second complex number." << std::endl;
        return 1;
    }

    ComplexNumber c1(r1, i1);
    ComplexNumber c2(r2, i2);

    // Perform addition using the overloaded operator
    ComplexNumber sum = c1 + c2; // This will modify c1 due to the robustness issue

    // Print the sum
    std::cout << sum << std::endl;

    // For demonstration of robustness issue: c1 is also modified
    // std::cout << "Original c1 after addition: " << c1 << std::endl;

    return 0;
}