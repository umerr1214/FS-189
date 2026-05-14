#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void print() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
    }

    // Semantic Error: The '+' operator should return a Complex object by value,
    // not a reference to a local temporary object. Returning a reference
    // to 'result' (a local variable) causes a dangling reference once 'result'
    // is destroyed at the end of the function call, leading to undefined behavior.
    Complex& operator+(const Complex& other) const {
        Complex result(real + other.real, imaginary + other.imaginary);
        return result; // Returning reference to local variable
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2; // This line might result in c3 holding garbage values due to the dangling reference.
    std::cout << "c1 = "; c1.print(); std::cout << std::endl;
    std::cout << "c2 = "; c2.print(); std::cout << std::endl;
    std::cout << "c1 + c2 = "; c3.print(); std::cout << std::endl; // Output is undefined behavior

    Complex c4(5.0, -3.0);
    Complex c5(2.0, 1.0);
    Complex c6 = c4 + c5; // This line might result in c6 holding garbage values.
    std::cout << "c4 = "; c4.print(); std::cout << std::endl;
    std::cout << "c5 = "; c5.print(); std::cout << std::endl;
    std::cout << "c4 + c5 = "; c6.print(); std::cout << std::endl; // Output is undefined behavior

    return 0;
}