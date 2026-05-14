#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // Required for std::fixed and std::setprecision

class Calculator3067 {
public:
    int add(int a, int b) {
        // Robustness Issue: No overflow check.
        // For very large 'a' and 'b', a + b can exceed INT_MAX,
        // leading to integer overflow and incorrect results.
        return a + b;
    }

    int add(int a, int b, int c) {
        // Robustness Issue: No overflow check.
        // Similar to the two-integer version, this can overflow.
        return a + b + c;
    }

    double add(double a, double b) {
        // Double precision arithmetic inherently handles large ranges,
        // but precision can be a factor, though not a robustness issue in this simple context.
        return a + b;
    }
};

int main() {
    Calculator3067 calculator;

    std::cout << "Adding two integers (10, 20): " << calculator.add(10, 20) << std::endl;
    std::cout << "Adding two integers (-5, 15): " << calculator.add(-5, 15) << std::endl;
    // Robustness Issue demonstration: Integer overflow for add(int, int)
    std::cout << "Adding two integers (" << std::numeric_limits<int>::max() << ", 1) [OVERFLOW TEST]: "
              << calculator.add(std::numeric_limits<int>::max(), 1) << std::endl;

    std::cout << "Adding three integers (1, 2, 3): " << calculator.add(1, 2, 3) << std::endl;
    std::cout << "Adding three integers (100, -50, 20): " << calculator.add(100, -50, 20) << std::endl;
    // Robustness Issue demonstration: Integer overflow for add(int, int, int)
    std::cout << "Adding three integers (" << std::numeric_limits<int>::max() << ", 1, 1) [OVERFLOW TEST]: "
              << calculator.add(std::numeric_limits<int>::max(), 1, 1) << std::endl;

    std::cout << std::fixed << std::setprecision(1); // For consistent double output
    std::cout << "Adding two doubles (10.5, 20.3): " << calculator.add(10.5, 20.3) << std::endl;
    std::cout << "Adding two doubles (-2.5, 7.0): " << calculator.add(-2.5, 7.0) << std::endl;
    std::cout << std::setprecision(6); // Reset precision to default

    return 0;
}