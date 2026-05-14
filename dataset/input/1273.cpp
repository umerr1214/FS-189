#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // For std::fixed, std::setprecision

class Calculator {
public:
    // Overloaded method to add two integers
    // Robustness Issue: Lacks overflow detection for int addition.
    int add(int a, int b) {
        // For simplicity and to demonstrate the robustness issue,
        // no overflow check is performed here.
        return a + b;
    }

    // Overloaded method to add two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Overloaded method to add two floats
    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Set precision for floating-point output for consistency in testing
    std::cout << std::fixed << std::setprecision(6);

    // Demonstrate various additions, including the int overflow issue
    // This main function is for direct execution to show the problem.
    // The driver in the JSON will use std::cin for specific test cases.

    std::cout << "--- Demonstrating Calculator (Robustness Issue) ---\n";

    // Regular int addition
    std::cout << "Int: 5 + 10 = " << calc.add(5, 10) << std::endl;

    // Demonstrate int overflow (robustness issue)
    int max_int = std::numeric_limits<int>::max();
    std::cout << "Int Overflow: " << max_int << " + 1 = " << calc.add(max_int, 1) << std::endl;
    std::cout << "Int Overflow: " << max_int << " + 10 = " << calc.add(max_int, 10) << std::endl;

    // Regular double addition
    std::cout << "Double: 15.5 + 2.3 = " << calc.add(15.5, 2.3) << std::endl;
    std::cout << "Double: 0.1 + 0.2 = " << calc.add(0.1, 0.2) << std::endl;

    // Regular float addition
    std::cout << "Float: 7.1f + 8.2f = " << calc.add(7.1f, 8.2f) << std::endl;
    std::cout << "Float: 100.0f + (-50.5f) = " << calc.add(100.0f, -50.5f) << std::endl;

    return 0;
}