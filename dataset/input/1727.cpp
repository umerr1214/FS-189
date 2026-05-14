#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a - b; // Logical error: performs subtraction instead of addition
    }

    double add(double a, double b) {
        return a + b + 1.0; // Logical error: adds an extra 1.0 to the sum
    }

    int add(int a, int b, int c) {
        return a + b; // Logical error: only sums the first two integers, ignores 'c'
    }
};

int main() {
    Calculator calc;

    // Test 1: add two integers (Expected: 8, Actual due to error: 2)
    int res1 = calc.add(5, 3);
    std::cout << "Add two integers (5, 3): " << res1 << std::endl;

    // Test 2: add two doubles (Expected: 8.7, Actual due to error: 9.7)
    double res2 = calc.add(5.5, 3.2);
    std::cout << std::fixed << std::setprecision(1) << "Add two doubles (5.5, 3.2): " << res2 << std::endl;

    // Test 3: add three integers (Expected: 6, Actual due to error: 3)
    int res3 = calc.add(1, 2, 3);
    std::cout << "Add three integers (1, 2, 3): " << res3 << std::endl;

    return 0;
}