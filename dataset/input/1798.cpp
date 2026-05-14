#include <iostream>

// Class design as per question, with a syntax error
class MathOperations {
public:
    // Method to multiply two integers
    int multiply(int a, int b) {
        return a * b;
    }

    // Method to multiply three double values
    double multiply(double a, double b, double c) {
        return a * b * c;
    } // Missing semicolon after class definition, a common syntax error
}; // This semicolon is missing, causing a syntax error

int main() {
    MathOperations math;

    // Test integer multiplication
    int int_result = math.multiply(5, 10);
    std::cout << "Product of 5 and 10 (int): " << int_result << std::endl;

    // Test double multiplication
    double double_result = math.multiply(2.5, 3.0, 4.0);
    std::cout << "Product of 2.5, 3.0, and 4.0 (double): " << double_result << std::endl;

    return 0;
}