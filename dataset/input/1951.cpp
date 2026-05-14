#include <iostream>
#include <limits> // For INT_MAX/MIN
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    // Overloaded add method for two integers
    int add(int num1, int num2) {
        long long sum_ll = static_cast<long long>(num1) + num2;
        // Robustness issue: Potential silent truncation if sum_ll exceeds int range.
        // No check for overflow/underflow before casting back to int.
        return static_cast<int>(sum_ll);
    }

    // Overloaded add method for two doubles
    double add(double num1, double num2) {
        return num1 + num2;
    }

    // Overloaded add method for three integers
    int add(int num1, int num2, int num3) {
        long long sum_ll = static_cast<long long>(num1) + num2 + num3;
        // Robustness issue: Potential silent truncation if sum_ll exceeds int range.
        // No check for overflow/underflow before casting back to int.
        return static_cast<int>(sum_ll);
    }
};

int main() {
    Calculator calc;

    std::cout << "Testing Calculator with potential robustness issues:\n";

    // Test 1: Standard integer addition
    std::cout << "add(10, 20): " << calc.add(10, 20) << std::endl;

    // Test 2: Standard double addition
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "add(10.5, 20.3): " << calc.add(10.5, 20.3) << std::endl;

    // Test 3: Standard three integer addition
    std::cout << "add(1, 2, 3): " << calc.add(1, 2, 3) << std::endl;

    // Test 4: Integer overflow scenario for add(int, int)
    // INT_MAX is typically 2147483647 for a 32-bit int
    int a = std::numeric_limits<int>::max() - 10; // e.g., 2147483637
    int b = 20;
    // Expected mathematical sum: 2147483637 + 20 = 2147483657 (exceeds INT_MAX)
    // Casting 0x80000009 (2147483657) to signed int results in -2147483639
    std::cout << "add(INT_MAX - 10, 20): " << calc.add(a, b) << std::endl;

    // Test 5: Integer underflow scenario for add(int, int, int)
    // INT_MIN is typically -2147483648 for a 32-bit int
    int x = std::numeric_limits<int>::min() + 10; // e.g., -2147483638
    int y = -5;
    int z = -10;
    // Expected mathematical sum: -2147483638 - 5 - 10 = -2147483653 (below INT_MIN)
    // Casting 0x8000000B (-2147483653) to signed int results in 2147483643
    std::cout << "add(INT_MIN + 10, -5, -10): " << calc.add(x, y, z) << std::endl;

    return 0;
}