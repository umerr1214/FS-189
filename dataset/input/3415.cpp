#include <iostream>
#include <limits>   // For std::numeric_limits
#include <iomanip>  // For std::fixed and std::setprecision

template <typename T>
T get_absolute_value(T val) {
    // Robustness Issue: This custom implementation has a known problem for the most negative
    // integer value (e.g., std::numeric_limits<int>::min()).
    // Negating it results in an overflow, which is undefined behavior in C++ for signed integers.
    // On many systems using two's complement, -INT_MIN wraps around to INT_MIN itself,
    // which is mathematically incorrect for an absolute value.
    if (val < 0) {
        return -val; // Potential overflow for T = int, val = std::numeric_limits<int>::min()
    }
    return val;
}

int main() {
    std::cout << std::fixed << std::setprecision(3); // For consistent float/double output

    // Demonstrate with int
    int int_val1 = -10;
    std::cout << "Absolute value of " << int_val1 << " (int): " << get_absolute_value(int_val1) << std::endl;

    int int_val2 = 5;
    std::cout << "Absolute value of " << int_val2 << " (int): " << get_absolute_value(int_val2) << std::endl;

    int int_val3 = 0;
    std::cout << "Absolute value of " << int_val3 << " (int): " << get_absolute_value(int_val3) << std::endl;

    // Robustness issue demonstration: INT_MIN overflow
    int min_int = std::numeric_limits<int>::min();
    std::cout << "Absolute value of " << min_int << " (int): " << get_absolute_value(min_int) << std::endl;

    // Demonstrate with long long
    long long ll_val1 = -123456789012345LL;
    std::cout << "Absolute value of " << ll_val1 << " (long long): " << get_absolute_value(ll_val1) << std::endl;

    long long ll_val2 = std::numeric_limits<long long>::min();
    std::cout << "Absolute value of " << ll_val2 << " (long long): " << get_absolute_value(ll_val2) << std::endl;

    // For floating point types, this specific overflow doesn't apply, but the function still works.
    float float_val = -3.14f;
    std::cout << "Absolute value of " << float_val << " (float): " << get_absolute_value(float_val) << std::endl;

    return 0;
}