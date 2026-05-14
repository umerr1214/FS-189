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
    // Readability/Efficiency Issue:
    // - Uses unnecessary temporary variables and multiple lines for a simple sum.
    // - Could be a single, more concise return statement.
    int add(int firstNum, int secondNum, int thirdNum) {
        int intermediateSum = firstNum;
        intermediateSum = intermediateSum + secondNum;
        int finalResult = intermediateSum + thirdNum;
        return finalResult;
    }
};

int main() {
    Calculator calc;

    // Test add(int, int)
    std::cout << "Adding two integers (10, 20): " << calc.add(10, 20) << std::endl;

    // Test add(double, double)
    std::cout << "Adding two doubles (1.5, 2.5): " << std::fixed << std::setprecision(1) << calc.add(1.5, 2.5) << std::endl;
    std::cout << std::defaultfloat; // Reset float formatting

    // Test add(int, int, int)
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    std::cout << "Adding three integers (" << val1 << ", " << val2 << ", " << val3 << "): " << calc.add(val1, val2, val3) << std::endl;

    return 0;
}