#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // For std::fixed and std::setprecision for doubles

class Calculator {
public:
    int add(int a, int b) {
        // No overflow check implemented
        return a + b;
    }

    double add(double a, double b) {
        // No explicit handling for potential precision loss with extreme values
        return a + b;
    }

    int add(int a, int b, int c) {
        // No overflow check implemented
        return a + b + c;
    }
};

int main() {
    Calculator myCalc;

    std::cout << "--- Robustness Issue Demonstration ---" << '\n';

    // Integer overflow for two integers
    int val1_int_overflow_a = std::numeric_limits<int>::max() - 5;
    int val1_int_overflow_b = 10;
    int result_int_overflow_2 = myCalc.add(val1_int_overflow_a, val1_int_overflow_b);
    std::cout << "Add two integers (" << val1_int_overflow_a << " + " << val1_int_overflow_b << "): "
              << result_int_overflow_2 << '\n'; // Expected to wrap around

    // Floating-point precision issue for two doubles
    double val_double_large = 1.2345678901234567e+300; // A very large double
    double val_double_small = 1.0;                     // A relatively small double
    double result_double_precision = myCalc.add(val_double_large, val_double_small);
    std::cout << std::fixed << std::setprecision(15); // For consistent double output
    std::cout << "Add two doubles (" << val_double_large << " + " << val_double_small << "): "
              << result_double_precision << '\n'; // Expected to show no change or minimal change from val_double_large

    // Integer overflow for three integers
    int val_three_int_a = std::numeric_limits<int>::max() / 2;
    int val_three_int_b = std::numeric_limits<int>::max() / 2;
    int val_three_int_c = 100;
    int result_int_overflow_3 = myCalc.add(val_three_int_a, val_three_int_b, val_three_int_c);
    std::cout << "Add three integers (" << val_three_int_a << " + " << val_three_int_b << " + " << val_three_int_c << "): "
              << result_int_overflow_3 << '\n'; // Expected to wrap around

    return 0;
}