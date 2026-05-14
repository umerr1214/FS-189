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

    // Adds three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    // Test cases for add(int, int)
    std::cout << "Integer Addition (Two):" << std::endl;
    std::cout << "add(5, 7) = " << calc.add(5, 7) << std::endl;          // Expected: 12
    std::cout << "add(-10, 3) = " << calc.add(-10, 3) << std::endl;      // Expected: -7
    std::cout << "add(0, 100) = " << calc.add(0, 100) << std::endl;      // Expected: 100
    std::cout << "add(2000000000, 100000000) = " << calc.add(2000000000, 100000000) << std::endl; // Expected: 2100000000

    // Test cases for add(double, double)
    std::cout << "\nDouble Addition:" << std::endl;
    std::cout << std::fixed << std::setprecision(2); // Set precision for consistent double output
    std::cout << "add(5.5, 2.3) = " << calc.add(5.5, 2.3) << std::endl;  // Expected: 7.80
    std::cout << "add(-1.2, 0.7) = " << calc.add(-1.2, 0.7) << std::endl; // Expected: -0.50
    std::cout << "add(10.0, 0.0) = " << calc.add(10.0, 0.0) << std::endl; // Expected: 10.00

    // Test cases for add(int, int, int)
    std::cout << "\nInteger Addition (Three):" << std::endl;
    std::cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << std::endl;    // Expected: 6
    std::cout << "add(10, -5, 2) = " << calc.add(10, -5, 2) << std::endl; // Expected: 7
    std::cout << "add(-1, -2, -3) = " << calc.add(-1, -2, -3) << std::endl; // Expected: -6
    std::cout << "add(0, 0, 0) = " << calc.add(0, 0, 0) << std::endl;    // Expected: 0

    return 0;
}