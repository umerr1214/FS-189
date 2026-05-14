#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getter methods for testing
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overload + operator with a semantic error
    // It modifies 'this' object and returns it, instead of returning a new ComplexNumber object
    // and leaving the operands unchanged.
    ComplexNumber operator+(const ComplexNumber& other) { // Not const-qualified, as it modifies 'this'
        real += other.real;
        imaginary += other.imaginary;
        return *this; // Returns the modified 'this' object
    }

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

int main() {
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(1.5, -2.0);
    ComplexNumber c3 = c1 + c2; // This will modify c1
    
    std::cout << "c1: "; c1.print(); // c1 is now 4.0 + 1.0i
    std::cout << "c2: "; c2.print();
    std::cout << "c3 (c1 + c2): "; c3.print(); // Expected: 4.0 + 1.0i, Actual: 4.0 + 1.0i (but c1 is changed)

    ComplexNumber c4(0.0, 0.0);
    ComplexNumber c5(5.0, 7.0);
    ComplexNumber c6 = c4 + c5; // This will modify c4
    std::cout << "c4: "; c4.print(); // c4 is now 5.0 + 7.0i
    std::cout << "c5: "; c5.print();
    std::cout << "c6 (c4 + c5): "; c6.print(); // Expected: 5.0 + 7.0i, Actual: 5.0 + 7.0i (but c4 is changed)

    ComplexNumber c7(-1.0, -1.0);
    ComplexNumber c8(1.0, 1.0);
    ComplexNumber c9 = c7 + c8; // This will modify c7
    std::cout << "c7: "; c7.print(); // c7 is now 0.0 + 0.0i
    std::cout << "c8: "; c8.print();
    std::cout << "c9 (c7 + c8): "; c9.print(); // Expected: 0.0 + 0.0i, Actual: 0.0 + 0.0i (but c7 is changed)

    return 0;
}