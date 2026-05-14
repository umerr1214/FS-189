#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        return a * b; // Logical Error: Should be a + b
    }

    int add(int a, int b, int c) {
        return a + b + c + 1; // Logical Error: Should be a + b + c
    }

    double add(double a, double b) {
        return a - b; // Logical Error: Should be a + b
    }
};

int main() {
    Calculator calc;
    std::cout << "Sum of 1 and 2 (int): " << calc.add(1, 2) << std::endl; // Expected: 3, Actual: 2
    std::cout << "Sum of 1, 2, and 3 (int): " << calc.add(1, 2, 3) << std::endl; // Expected: 6, Actual: 7
    std::cout << std::fixed << std::setprecision(1) << "Sum of 1.5 and 2.5 (double): " << calc.add(1.5, 2.5) << std::endl; // Expected: 4.0, Actual: -1.0
    std::cout << "Sum of 5 and 10 (int): " << calc.add(5, 10) << std::endl; // Expected: 15, Actual: 50
    std::cout << "Sum of 10, 20, and 30 (int): " << calc.add(10, 20, 30) << std::endl; // Expected: 60, Actual: 61
    std::cout << std::fixed << std::setprecision(1) << "Sum of 0.1 and 0.2 (double): " << calc.add(0.1, 0.2) << std::endl; // Expected: 0.3, Actual: -0.1
    return 0;
}