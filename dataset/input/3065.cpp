#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    // Logical Error: Should be a + b + c, but incorrectly subtracts c
    int add(int a, int b, int c) {
        return a + b - c; // Incorrect logic
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Test 1: Add two integers
    int sum1 = calc.add(5, 10);
    std::cout << "Sum of 5 and 10 (int): " << sum1 << std::endl;

    // Test 2: Add three integers (this will expose the error)
    int sum2 = calc.add(1, 2, 3); // Expected: 1+2+3 = 6, Actual: 1+2-3 = 0
    std::cout << "Sum of 1, 2, and 3 (int): " << sum2 << std::endl;

    // Test 3: Add two doubles
    double sum3 = calc.add(5.5, 4.5);
    std::cout << std::fixed << std::setprecision(1) << "Sum of 5.5 and 4.5 (double): " << sum3 << std::endl;

    return 0;
}