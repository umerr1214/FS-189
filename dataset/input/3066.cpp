#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Semantic Error: Returns int, causing truncation of double sum
    // The method signature should be 'double add(double a, double b)'
    int add(double a, double b) {
        return static_cast<int>(a + b); // Explicit cast to int, losing fractional part
    }
};

int main() {
    Calculator calc;

    // Test 1: Add two integers
    int sum1 = calc.add(5, 10);
    std::cout << "Sum of 5 and 10 (int): " << sum1 << std::endl;

    // Test 2: Add three integers
    int sum2 = calc.add(1, 2, 3);
    std::cout << "Sum of 1, 2, and 3 (int): " << sum2 << std::endl;

    // Test 3: Add two doubles (this will expose the semantic error)
    double val_a = 5.6;
    double val_b = 4.7;
    // The method add(double, double) returns int, so the sum 10.3 will be truncated to 10
    double sum3_semantic = calc.add(val_a, val_b); // Expected: 10.3, Actual: 10.0 (due to truncation)

    std::cout << std::fixed << std::setprecision(1) << "Sum of " << val_a << " and " << val_b << " (double, semantic error): " << sum3_semantic << std::endl;

    return 0;
}