#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getter methods (for testing/display)
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overload binary + operator (Robustness Issue: modifies *this)
    // This operator behaves like '+=' rather than a pure addition,
    // which is unexpected for a binary '+' and leads to side effects.
    ComplexNumber operator+(const ComplexNumber& other) {
        this->real += other.real;
        this->imaginary += other.imaginary;
        return *this; // Returns the modified *this
    }

    // Method to get string representation for display
    std::string toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << real;
        if (imaginary >= 0) {
            oss << "+" << imaginary << "i";
        } else {
            oss << imaginary << "i";
        }
        return oss.str();
    }
};

// Driver code
int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3(-0.5, 1.5);
    ComplexNumber c4(2.5, -3.5);
    ComplexNumber cx1(1.0, 1.0);
    ComplexNumber cx2(2.0, 2.0);
    ComplexNumber cx3(3.0, 3.0);

    // Test Case 1: c1 + c2
    // Expected: 4.00+6.00i, but c1 itself will also become 4.00+6.00i
    ComplexNumber result_tc1 = c1 + c2;
    std::cout << result_tc1.toString() << std::endl;
    std::cout << c1.toString() << std::endl; // Shows c1 has changed

    // Test Case 2: c3 + c4
    // Expected: 2.00-2.00i, but c3 itself will also become 2.00-2.00i
    ComplexNumber result_tc2 = c3 + c4;
    std::cout << result_tc2.toString() << std::endl;
    std::cout << c3.toString() << std::endl; // Shows c3 has changed

    // Test Case 3: Chained addition (demonstrates issue more clearly)
    // (cx1 + cx2) evaluates, cx1 becomes (3,3). Then (3,3) + cx3 evaluates, cx1 becomes (6,6).
    // The final result is correct, but cx1 is unexpectedly modified multiple times.
    ComplexNumber result_tc3 = cx1 + cx2 + cx3;
    std::cout << result_tc3.toString() << std::endl;
    std::cout << cx1.toString() << std::endl; // Shows cx1 has changed significantly
    
    return 0;
}