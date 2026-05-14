#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        // Logical error: Subtracts instead of adds
        return a - b;
    }

    double add(double a, double b) {
        // Logical error: Returns a fixed incorrect value
        return 100.0;
    }

    int add(int a, int b, int c) {
        // Logical error: Only adds the first two integers
        return a + b;
    }
};

int main() {
    Calculator calc;
    std::cout << "Adding two integers (5, 7): " << calc.add(5, 7) << std::endl; // Expected 12, gets -2
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Adding two doubles (5.5, 7.2): " << calc.add(5.5, 7.2) << std::endl; // Expected 12.7, gets 100.0
    std::cout << "Adding three integers (1, 2, 3): " << calc.add(1, 2, 3) << std::endl; // Expected 6, gets 3
    return 0;
}