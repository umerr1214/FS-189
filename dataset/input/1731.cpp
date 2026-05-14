#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

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

    // Adds three integers, using long long for robustness against potential overflow
    long long add(int a, int b, int c) {
        return static_cast<long long>(a) + b + c;
    }
};

int main() {
    Calculator calc;

    // Test add(int, int)
    std::cout << "Adding two integers (10, 20): " << calc.add(10, 20) << std::endl;

    // Test add(double, double)
    std::cout << "Adding two doubles (1.5, 2.5): " << std::fixed << std::setprecision(1) << calc.add(1.5, 2.5) << std::endl;
    std::cout << std::defaultfloat; // Reset float formatting

    // Test add(int, int, int) with values that would cause integer overflow
    // if the return type was int, demonstrating the robustness of long long.
    int val1 = 1000000000;
    int val2 = 1000000000;
    int val3 = 1000000000;
    std::cout << "Adding three integers (" << val1 << ", " << val2 << ", " << val3 << "): " << calc.add(val1, val2, val3) << std::endl;

    return 0;
}