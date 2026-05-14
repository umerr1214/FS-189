#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For INT_MAX, though not directly used in logic, it's relevant for context

class Calculator {
public:
    // Adds two integers
    int add(int a, int b) {
        return a + b;
    }

    // Adds two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Adds three integers
    // Robustness Issue: Returns int, which is susceptible to overflow for large inputs.
    // A more robust solution would use long long to prevent potential data loss.
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    // Test add(int, int)
    std::cout << "Adding two integers (10, 20): " << calc.add(10, 20) << std::endl;

    // Test add(double, double)
    std::cout << "Adding two doubles (1.5, 2.5): " << std::fixed << std::setprecision(1) << calc.add(1.5, 2.5) << std::endl;
    std::cout << std::defaultfloat; // Reset float formatting

    // Test add(int, int, int) with values that will cause integer overflow
    // on systems where int is 32-bit (INT_MAX approx 2.1 billion)
    int val1 = 1000000000;
    int val2 = 1000000000;
    int val3 = 1000000000;
    std::cout << "Adding three integers (" << val1 << ", " << val2 << ", " << val3 << "): " << calc.add(val1, val2, val3) << std::endl;

    return 0;
}