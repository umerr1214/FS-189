#include <iostream>
#include <limits>   // For numeric_limits
#include <cmath>    // For isnan, nan
#include <iomanip>  // For setprecision, fixed, scientific

// Correctly designed MathOperations class
class MathOperations {
public:
    /**
     * @brief Multiplies two integers and returns their product.
     * @param num1 The first integer.
     * @param num2 The second integer.
     * @return The product of num1 and num2.
     */
    int multiply(int num1, int num2) {
        return num1 * num2;
    }

    /**
     * @brief Multiplies three double values and returns their product.
     * @param val1 The first double value.
     * @param val2 The second double value.
     * @param val3 The third double value.
     * @return The product of val1, val2, and val3.
     */
    double multiply(double val1, double val2, double val3) {
        return val1 * val2 * val3;
    }
};

int main() {
    MathOperations math_ops;

    std::cout << std::fixed << std::setprecision(1); // Default precision for doubles

    // Test cases for multiply(int, int)
    std::cout << "Testing multiply(int, int):\n";
    std::cout << "5 * 10 = " << math_ops.multiply(5, 10) << "\n";
    std::cout << "-3 * 7 = " << math_ops.multiply(-3, 7) << "\n";
    std::cout << "0 * 100 = " << math_ops.multiply(0, 100) << "\n";
    std::cout << "30000 * 40000 = " << math_ops.multiply(30000, 40000) << "\n";

    // Test cases for multiply(double, double, double)
    std::cout << "\nTesting multiply(double, double, double):\n";
    std::cout << "1.5 * 2.0 * 3.0 = " << math_ops.multiply(1.5, 2.0, 3.0) << "\n";
    std::cout << "-0.5 * 4.0 * 2.5 = " << math_ops.multiply(-0.5, 4.0, 2.5) << "\n";
    std::cout << "10.0 * 0.1 * 5.0 = " << math_ops.multiply(10.0, 0.1, 5.0) << "\n";
    
    // Inputting NaN
    double nan_val = std::numeric_limits<double>::quiet_NaN();
    std::cout << "NaN * 2.0 * 3.0 = " << math_ops.multiply(nan_val, 2.0, 3.0) << "\n";

    // Test with very small numbers
    std::cout << std::scientific << std::setprecision(6); // Switch to scientific for this one
    std::cout << "1.0e-10 * 2.0e-10 * 3.0e-10 = " << math_ops.multiply(1.0e-10, 2.0e-10, 3.0e-10) << "\n";
    std::cout << std::fixed << std::setprecision(1); // Reset for potential future outputs

    return 0;
}