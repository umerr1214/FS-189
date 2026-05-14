#include <iostream>
#include <iomanip> // Required for std::fixed, std::setprecision

class Calculator {
public:
    // Overloaded method to add two integers, returning an int.
    int add(int a, int b) {
        return a + b;
    }

    // Overloaded method to add two doubles, returning a double.
    double add(double a, double b) {
        return a + b;
    }

    // Overloaded method to add two floats, returning a float.
    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Set precision for floating-point output for consistency in testing
    std::cout << std::fixed << std::setprecision(6);

    // This main function is for direct execution to demonstrate functionality.
    // The driver in the JSON will use std::cin for specific test cases.

    std::cout << "--- Demonstrating Calculator (Correct Version) ---\n";

    // Test int addition
    std::cout << "Int: 10 + 20 = " << calc.add(10, 20) << std::endl;
    std::cout << "Int: -5 + 15 = " << calc.add(-5, 15) << std::endl;

    // Test double addition
    std::cout << "Double: 10.5 + 20.3 = " << calc.add(10.5, 20.3) << std::endl;
    std::cout << "Double: 0.1 + 0.2 = " << calc.add(0.1, 0.2) << std::endl;

    // Test float addition
    std::cout << "Float: 1.1f + 2.2f = " << calc.add(1.1f, 2.2f) << std::endl;
    std::cout << "Float: 100.0f + (-25.5f) = " << calc.add(100.0f, -25.5f) << std::endl;

    return 0;
}