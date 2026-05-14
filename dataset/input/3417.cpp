#include <iostream>
#include <cmath>    // For std::abs with floating-point types
#include <cstdlib>  // For std::abs with integral types (overloads are often in cmath too)
#include <limits>   // For std::numeric_limits
#include <iomanip>  // For std::fixed and std::setprecision

template <typename T>
T get_absolute_value(T val) {
    // Correct Version: Uses std::abs which is overloaded for various numeric types
    // and handles edge cases (like INT_MIN) as robustly as possible within standard library conventions.
    return std::abs(val);
}

int main() {
    std::cout << std::fixed << std::setprecision(3); // For consistent float/double output

    // Demonstrate with int
    int int_val1 = -100;
    std::cout << "Absolute value of " << int_val1 << " (int): " << get_absolute_value(int_val1) << std::endl;

    int int_val2 = 25;
    std::cout << "Absolute value of " << int_val2 << " (int): " << get_absolute_value(int_val2) << std::endl;

    int int_val3 = 0;
    std::cout << "Absolute value of " << int_val3 << " (int): " << get_absolute_value(int_val3) << std::endl;

    // Test with INT_MIN - std::abs typically returns INT_MIN for this case on systems
    // where 2's complement is used and the mathematical absolute value cannot be represented.
    // This is the standard and most robust behavior for std::abs under these conditions.
    int min_int = std::numeric_limits<int>::min();
    std::cout << "Absolute value of " << min_int << " (int): " << get_absolute_value(min_int) << std::endl;

    // Demonstrate with double
    double double_val1 = -123.456;
    std::cout << "Absolute value of " << double_val1 << " (double): " << get_absolute_value(double_val1) << std::endl;

    double double_val2 = 789.012;
    std::cout << "Absolute value of " << double_val2 << " (double): " << get_absolute_value(double_val2) << std::endl;

    double double_val3 = -0.0;
    std::cout << "Absolute value of " << double_val3 << " (double): " << get_absolute_value(double_val3) << std::endl;

    return 0;
}