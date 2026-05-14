#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Calculator {
public:
    int add(int a, int b) {
        // Logical error: performs subtraction instead of addition
        return a - b; 
    }

    double add(double a, double b) {
        // Logical error: performs multiplication instead of addition
        return a * b; 
    }

    int add(int a, int b, int c) {
        // Logical error: subtracts c instead of adding it
        return a + b - c; 
    }
};

int main() {
    Calculator calc;
    std::cout << "Add two ints (5, 3): " << calc.add(5, 3) << std::endl; // Expected: 8, Actual: 2
    std::cout << std::fixed << std::setprecision(1); // Set precision for doubles
    std::cout << "Add two doubles (5.5, 3.2): " << calc.add(5.5, 3.2) << std::endl; // Expected: 8.7, Actual: 17.6
    std::cout << "Add three ints (1, 2, 3): " << calc.add(1, 2, 3) << std::endl; // Expected: 6, Actual: 0
    return 0;
}