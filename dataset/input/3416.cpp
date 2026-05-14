#include <iostream>
#include <limits>   // For std::numeric_limits
#include <iomanip>  // For std::fixed and std::setprecision

// No <cmath> or <cstdlib> to avoid using std::abs directly

template <typename T>
T get_absolute_value(T val) {
    // Readability / Efficiency Issue:
    // This approach uses a conditional multiplication, which is less efficient than a direct
    // if-else structure or using std::abs. It also can be considered less readable
    // than the idiomatic std::abs or a simple conditional negation.
    // For integral types, it also shares the INT_MIN overflow issue, but the primary classification
    // here is the less optimal style/efficiency rather than just the correctness failure.
    return val * (val < 0 ? static_cast<T>(-1) : static_cast<T>(1));
}

int main() {
    std::cout << std::fixed << std::setprecision(3); // For consistent float/double output

    // Demonstrate with float
    float float_val1 = -7.89f;
    std::cout << "Absolute value of " << float_val1 << " (float): " << get_absolute_value(float_val1) << std::endl;

    float float_val2 = 12.34f;
    std::cout << "Absolute value of " << float_val2 << " (float): " << get_absolute_value(float_val2) << std::endl;

    // Demonstrate with int
    int int_val1 = -20;
    std::cout << "Absolute value of " << int_val1 << " (int): " << get_absolute_value(int_val1) << std::endl;

    int int_val2 = 15;
    std::cout << "Absolute value of " << int_val2 << " (int): " << get_absolute_value(int_val2) << std::endl;

    int int_val3 = 0;
    std::cout << "Absolute value of " << int_val3 << " (int): " << get_absolute_value(int_val3) << std::endl;

    // This version also has the INT_MIN issue, similar to a manual negation.
    // However, the primary error type is readability/efficiency for *how* it's implemented,
    // as std::abs is more idiomatic and often optimized.
    int min_int = std::numeric_limits<int>::min();
    std::cout << "Absolute value of " << min_int << " (int): " << get_absolute_value(min_int) << std::endl;

    return 0;
}