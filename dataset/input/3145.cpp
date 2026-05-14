#include <iostream>
#include <limits> // For INT_MAX for demonstration, though not directly used in the Calculator logic

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

    // Adds three integers - Robustness issue: Does not handle potential integer overflow
    int add(int a, int b, int c) {
        // For very large inputs, this sum can exceed INT_MAX, leading to integer overflow
        // and incorrect results (undefined behavior, typically wrapping around).
        // A robust implementation might check for overflow or use a larger type like long long.
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    // Test add(int, int)
    std::cout << "add(10, 20): " << calc.add(10, 20) << std::endl; // Expected: 30
    std::cout << "add(-5, 15): " << calc.add(-5, 15) << std::endl; // Expected: 10

    // Test add(double, double)
    std::cout << "add(3.5, 2.1): " << calc.add(3.5, 2.1) << std::endl; // Expected: 5.6
    std::cout << "add(-10.0, 0.5): " << calc.add(-10.0, 0.5) << std::endl; // Expected: -9.5

    // Test add(int, int, int)
    std::cout << "add(1, 2, 3): " << calc.add(1, 2, 3) << std::endl; // Expected: 6
    std::cout << "add(100, -50, 20): " << calc.add(100, -50, 20) << std::endl; // Expected: 70

    // Robustness Issue Demonstration: Integer Overflow
    // INT_MAX is typically 2,147,483,647.
    // Summing three large positive integers can exceed this limit.
    // For example, 2000000000 + 2000000000 + 2000000000 = 6000000000
    // This will overflow a 32-bit signed int.
    // The actual output will be an incorrect, wrapped-around value (e.g., -294967296).
    std::cout << "add(2000000000, 2000000000, 2000000000): "
              << calc.add(2000000000, 2000000000, 2000000000) << std::endl; // Expected: 6000000000 (mathematically)

    return 0;
}