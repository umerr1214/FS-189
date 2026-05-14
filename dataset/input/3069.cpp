#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

/**
 * @brief A Calculator class providing overloaded addition methods.
 */
class Calculator3069 {
public:
    /**
     * @brief Adds two integers.
     * @param num1 The first integer operand.
     * @param num2 The second integer operand.
     * @return The sum of num1 and num2.
     */
    int add(int num1, int num2) {
        return num1 + num2;
    }

    /**
     * @brief Adds three integers.
     * @param num1 The first integer operand.
     * @param num2 The second integer operand.
     * @param num3 The third integer operand.
     * @return The sum of num1, num2, and num3.
     */
    int add(int num1, int num2, int num3) {
        return num1 + num2 + num3;
    }

    /**
     * @brief Adds two double-precision numbers.
     * @param dbl1 The first double operand.
     * @param dbl2 The second double operand.
     * @return The sum of dbl1 and dbl2.
     */
    double add(double dbl1, double dbl2) {
        return dbl1 + dbl2;
    }
};

int main() {
    Calculator3069 calculator;

    // Demonstrate adding two integers
    std::cout << "Adding two integers (10, 20): " << calculator.add(10, 20) << std::endl;
    std::cout << "Adding two integers (-5, 15): " << calculator.add(-5, 15) << std::endl;

    // Demonstrate adding three integers
    std::cout << "Adding three integers (1, 2, 3): " << calculator.add(1, 2, 3) << std::endl;
    std::cout << "Adding three integers (100, -50, 20): " << calculator.add(100, -50, 20) << std::endl;

    // Demonstrate adding two double-precision numbers
    std::cout << std::fixed << std::setprecision(1); // Set precision for consistent double output
    std::cout << "Adding two doubles (10.5, 20.3): " << calculator.add(10.5, 20.3) << std::endl;
    std::cout << "Adding two doubles (-2.5, 7.0): " << calculator.add(-2.5, 7.0) << std::endl;
    std::cout << std::setprecision(6); // Reset precision to default

    return 0;
}