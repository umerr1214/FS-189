#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Readability / Efficiency Issue:
    // This operator returns a pointer to a dynamically allocated ComplexNumber object.
    // This is inefficient due to heap allocation for a small object and
    // places a significant memory management burden (manual 'delete') on the caller.
    // It's also unidiomatic for C++ operator overloading.
    ComplexNumber* operator-() const {
        ComplexNumber* negated = new ComplexNumber(-real, -imaginary);
        return negated; // Caller is responsible for deleting this memory
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
    }
};

int main() {
    // Test case 1
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber* c2_ptr = -c1; // Receives a pointer
    c2_ptr->print();
    std::cout << std::endl;
    delete c2_ptr; // Manual memory cleanup

    // Test case 2
    ComplexNumber c3(-1.0, 2.5);
    ComplexNumber* c4_ptr = -c3;
    c4_ptr->print();
    std::cout << std::endl;
    delete c4_ptr;

    // Test case 3
    ComplexNumber c5(0.0, -7.0);
    ComplexNumber* c6_ptr = -c5;
    c6_ptr->print();
    std::cout << std::endl;
    delete c6_ptr;

    return 0;
}