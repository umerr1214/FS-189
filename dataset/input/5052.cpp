#include <iostream>
#include <string> // For potential string manipulation in test drivers.
#include <cstdlib> // Provides std::abs for integer types (int, long, long long).
                   // Does NOT necessarily provide overloads for float/double/long double.
                   // For floating-point types, <cmath> should be included.

// Function template definition with a semantic error
template <typename T>
T getAbsoluteValue(T value)
{
    // Semantic Error: Relying on std::abs from <cstdlib> for all numeric types.
    // If <cmath> is not included, calling std::abs with a float or double
    // might implicitly convert the argument to 'int' (if only std::abs(int) is visible)
    // before computing the absolute value, leading to loss of precision or incorrect results.
    return std::abs(value);
}

int main() {
    // Test cases
    int int_val_neg = -5;
    int int_val_pos = 10;
    float float_val_neg = -3.14f;
    float float_val_pos = 2.71f;
    double double_val_neg = -9.81;
    double double_val_pos = 1.2345;

    std::cout << "Testing getAbsoluteValue with semantic error (using std::abs from cstdlib for floats/doubles):" << std::endl;

    // For integer types, std::abs from <cstdlib> works correctly.
    std::cout << "Absolute value of " << int_val_neg << " (int): " << getAbsoluteValue(int_val_neg) << " (Expected: 5)" << std::endl;
    std::cout << "Absolute value of " << int_val_pos << " (int): " << getAbsoluteValue(int_val_pos) << " (Expected: 10)" << std::endl;

    // For floating-point types, this is where the semantic error manifests.
    // E.g., -3.14f might be implicitly converted to -3, then abs(-3) = 3.
    std::cout << "Absolute value of " << float_val_neg << " (float): " << getAbsoluteValue(float_val_neg) << " (Expected: 3.14, Actual: ~3)" << std::endl;
    std::cout << "Absolute value of " << float_val_pos << " (float): " << getAbsoluteValue(float_val_pos) << " (Expected: 2.71, Actual: ~2)" << std::endl;

    std::cout << "Absolute value of " << double_val_neg << " (double): " << getAbsoluteValue(double_val_neg) << " (Expected: 9.81, Actual: ~9)" << std::endl;
    std::cout << "Absolute value of " << double_val_pos << " (double): " << getAbsoluteValue(double_val_pos) << " (Expected: 1.2345, Actual: ~1)" << std::endl;

    return 0;
}