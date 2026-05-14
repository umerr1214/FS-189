#include <iostream>
#include <limits> // Required for std::numeric_limits

class Calculator {
public:
    // Adds two integers. Potential for integer overflow if sum exceeds INT_MAX.
    int add(int a, int b) {
        return a + b;
    }

    // Adds two doubles.
    double add(double a, double b) {
        return a + b;
    }

    // Adds three integers. Potential for integer overflow if sum exceeds INT_MAX.
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    std::cout << "Testing add(int, int):" << std::endl;
    std::cout << "add(5, 3) = " << calc.add(5, 3) << std::endl;           // Expected: 8
    std::cout << "add(-10, 7) = " << calc.add(-10, 7) << std::endl;       // Expected: -3
    std::cout << "add(0, 0) = " << calc.add(0, 0) << std::endl;           // Expected: 0
    // Robustness Issue: Integer overflow for large positive numbers
    std::cout << "add(INT_MAX, 1) = " << calc.add(std::numeric_limits<int>::max(), 1) << std::endl; // Expected: INT_MIN (overflow)
    // Robustness Issue: Integer underflow for large negative numbers
    std::cout << "add(INT_MIN, -1) = " << calc.add(std::numeric_limits<int>::min(), -1) << std::endl; // Expected: INT_MAX (underflow)

    std::cout << "\nTesting add(double, double):" << std::endl;
    std::cout << "add(5.5, 3.2) = " << calc.add(5.5, 3.2) << std::endl;           // Expected: 8.7
    std::cout << "add(-10.1, 7.5) = " << calc.add(-10.1, 7.5) << std::endl;       // Expected: -2.6
    std::cout << "add(0.0, 0.0) = " << calc.add(0.0, 0.0) << std::endl;           // Expected: 0.0
    std::cout << "add(123456789.123, 987654321.987) = " << calc.add(123456789.123, 987654321.987) << std::endl; // Expected: 1111111111.11

    std::cout << "\nTesting add(int, int, int):" << std::endl;
    std::cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << std::endl;             // Expected: 6
    std::cout << "add(-1, -2, -3) = " << calc.add(-1, -2, -3) << std::endl;       // Expected: -6
    std::cout << "add(10, -5, 2) = " << calc.add(10, -5, 2) << std::endl;         // Expected: 7
    // Robustness Issue: Integer overflow for large positive numbers
    std::cout << "add(INT_MAX - 1, 1, 1) = " << calc.add(std::numeric_limits<int>::max() - 1, 1, 1) << std::endl; // Expected: INT_MIN (overflow)

    return 0;
}