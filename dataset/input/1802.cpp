#include <iostream>
#include <limits>   // For numeric_limits
#include <cmath>    // For isnan, nan
#include <iomanip>  // For setprecision, fixed, scientific

// Class definition with readability/efficiency issues
class MathOperations {
    public:
    // Overloaded method to multiply two integers
    // Readability Issue: Poor variable names (i1, i2), inconsistent spacing.
    int multiply(int i1 ,int i2) {
    int   product_temp = i1 * i2; // Unnecessary temporary variable
        return product_temp;
    }

    // Overloaded method to multiply three double values
    // Readability Issue: Poor variable names (d1, d2, d3), inconsistent indentation.
    double multiply(double d1,
                     double d2,
                         double d3) {
        double result_val = d1 * d2 * d3;
        return result_val;
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