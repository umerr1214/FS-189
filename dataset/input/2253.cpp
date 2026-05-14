#include <iostream>
#include <limits> // Required for std::numeric_limits

class Calculator {
public:
    // Adds two integers. Declared const as it doesn't modify object state.
    int add(int a, int b) const {
        return a + b;
    }

    // Adds two doubles. Declared const as it doesn't modify object state.
    double add(double a, double b) const {
        return a + b;
    }

    // Adds three integers. Declared const as it doesn't modify object state.
    int add(int a, int b, int c) const {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    std::cout << "Testing add(int, int):" << std::endl;
    std::cout << "add(5, 3) = " << calc.add(5, 3) << std::endl;
    std::cout << "add(-10, 7) = " << calc.add(-10, 7) << std::endl;
    std::cout << "add(0, 0) = " << calc.add(0, 0) << std::endl;
    std::cout << "add(" << std::numeric_limits<int>::max() << ", 0) = " << calc.add(std::numeric_limits<int>::max(), 0) << std::endl;
    std::cout << "add(" << std::numeric_limits<int>::min() << ", 0) = " << calc.add(std::numeric_limits<int>::min(), 0) << std::endl;

    std::cout << "\nTesting add(double, double):" << std::endl;
    std::cout << "add(5.5, 3.2) = " << calc.add(5.5, 3.2) << std::endl;
    std::cout << "add(-10.1, 7.5) = " << calc.add(-10.1, 7.5) << std::endl;
    std::cout << "add(0.0, 0.0) = " << calc.add(0.0, 0.0) << std::endl;
    std::cout << "add(123456789.123, 987654321.987) = " << calc.add(123456789.123, 987654321.987) << std::endl;
    std::cout << "add(0.0000001, 0.0000002) = " << calc.add(0.0000001, 0.0000002) << std::endl;

    std::cout << "\nTesting add(int, int, int):" << std::endl;
    std::cout << "add(1, 2, 3) = " << calc.add(1, 2, 3) << std::endl;
    std::cout << "add(-1, -2, -3) = " << calc.add(-1, -2, -3) << std::endl;
    std::cout << "add(10, -5, 2) = " << calc.add(10, -5, 2) << std::endl;
    std::cout << "add(100, 200, 300) = " << calc.add(100, 200, 300) << std::endl;
    std::cout << "add(" << std::numeric_limits<int>::max() - 2 << ", 1, 1) = " << calc.add(std::numeric_limits<int>::max() - 2, 1, 1) << std::endl;

    return 0;
}