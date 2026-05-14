#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Declare the non-member operator+ as a friend.
    // SEMANTIC ERROR: The friend declaration specifies a return type of reference,
    // which is consistent with the semantic error in the operator's definition.
    friend ComplexNumber& operator+(const ComplexNumber& c1, const ComplexNumber& c2);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void print() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }
};

// Overload binary + operator (SEMANTIC ERROR: Returns a reference to a local temporary)
// This function compiles but leads to undefined behavior because 'result' is a local variable
// and its memory is deallocated after the function returns.
ComplexNumber& operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    ComplexNumber result(c1.real + c2.real, c1.imaginary + c2.imaginary);
    return result; // SEMANTIC ERROR: Returning reference to local variable 'result'
}

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3 = c1 + c2; // c3 will refer to deallocated memory, leading to undefined behavior
    std::cout << "c1: "; c1.print();
    std::cout << "c2: "; c2.print();
    std::cout << "c1 + c2 (potentially garbage): "; c3.print(); // Output is unpredictable

    return 0;
}