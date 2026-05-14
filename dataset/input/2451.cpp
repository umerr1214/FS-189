#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class MathOperations {
public:
    // Overloaded add method for two integers
    int add(int a, int b) const {
        return a + b;
    }

    // Overloaded add method for two doubles
    double add(double a, double b) const {
        return a + b;
    }

    // Overloaded add method for three integers
    int add(int a, int b, int c) const {
        return a + b + c;
    }
};

int main() {
    MathOperations mo;

    // Test add(int, int)
    std::cout << "add(5, 3) = " << mo.add(5, 3) << std::endl;
    std::cout << "add(-1, 10) = " << mo.add(-1, 10) << std::endl;
    std::cout << "add(0, 0) = " << mo.add(0, 0) << std::endl;

    // Test add(double, double)
    std::cout << std::fixed << std::setprecision(1); // Set precision for doubles
    std::cout << "add(5.5, 3.2) = " << mo.add(5.5, 3.2) << std::endl;
    std::cout << "add(-1.0, 10.5) = " << mo.add(-1.0, 10.5) << std::endl;
    std::cout << "add(0.0, 0.0) = " << mo.add(0.0, 0.0) << std::endl;

    // Test add(int, int, int)
    std::cout << std::setprecision(6); // Reset precision for int outputs (or default)
    std::cout << "add(1, 2, 3) = " << mo.add(1, 2, 3) << std::endl;
    std::cout << "add(-1, 0, 1) = " << mo.add(-1, 0, 1) << std::endl;
    std::cout << "add(10, -5, 2) = " << mo.add(10, -5, 2) << std::endl;

    return 0;
}