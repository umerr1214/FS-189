#include <iostream>

// Class design with a logical error
class MathOperations {
public:
    // Method to multiply two integers - LOGICAL ERROR: returns sum instead of product
    int multiply(int a, int b) {
        return a + b; // Should be a * b
    }

    // Method to multiply three double values - LOGICAL ERROR: returns sum instead of product
    double multiply(double a, double b, double c) {
        return a + b + c; // Should be a * b * c
    }
};

int main() {
    MathOperations math;

    // Test integer multiplication
    int int_val1 = 5;
    int int_val2 = 10;
    int int_result = math.multiply(int_val1, int_val2);
    std::cout << "Product of " << int_val1 << " and " << int_val2 << " (int): " << int_result << std::endl; // Expected: 50, Actual: 15

    // Test double multiplication
    double double_val1 = 2.5;
    double double_val2 = 3.0;
    double double_val3 = 4.0;
    double double_result = math.multiply(double_val1, double_val2, double_val3);
    std::cout << "Product of " << double_val1 << ", " << double_val2 << ", and " << double_val3 << " (double): " << double_result << std::endl; // Expected: 30.0, Actual: 9.5

    return 0;
}