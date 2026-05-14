#include <iostream>
#include <string> // For potential string manipulation in test drivers.
#include <cmath>  // Included for completeness, though not directly used in the flawed logic.

// Function template definition with a logical error
template <typename T>
T getAbsoluteValue(T value)
{
    // Logical Error: If value is negative, it returns the value itself.
    // If value is positive or zero, it returns the negative of the value.
    // This flips the sign for positive numbers and leaves negative numbers unchanged.
    if (value < 0) {
        return value; // Incorrect: Should be -value
    } else {
        return -value; // Incorrect: Should be value
    }
}

int main() {
    // Test cases
    int int_val_neg = -5;
    int int_val_pos = 10;
    int int_val_zero = 0;
    float float_val_neg = -3.14f;
    float float_val_pos = 2.71f;
    float float_val_zero = 0.0f;
    double double_val_neg = -9.81;
    double double_val_pos = 1.2345;
    double double_val_zero = 0.0;

    std::cout << "Testing getAbsoluteValue with logical error:" << std::endl;

    std::cout << "Absolute value of " << int_val_neg << " (int): " << getAbsoluteValue(int_val_neg) << " (Expected: 5, Actual: -5)" << std::endl;
    std::cout << "Absolute value of " << int_val_pos << " (int): " << getAbsoluteValue(int_val_pos) << " (Expected: 10, Actual: -10)" << std::endl;
    std::cout << "Absolute value of " << int_val_zero << " (int): " << getAbsoluteValue(int_val_zero) << " (Expected: 0, Actual: 0)" << std::endl;

    std::cout << "Absolute value of " << float_val_neg << " (float): " << getAbsoluteValue(float_val_neg) << " (Expected: 3.14, Actual: -3.14)" << std::endl;
    std::cout << "Absolute value of " << float_val_pos << " (float): " << getAbsoluteValue(float_val_pos) << " (Expected: 2.71, Actual: -2.71)" << std::endl;
    std::cout << "Absolute value of " << float_val_zero << " (float): " << getAbsoluteValue(float_val_zero) << " (Expected: 0.0, Actual: 0.0)" << std::endl;

    std::cout << "Absolute value of " << double_val_neg << " (double): " << getAbsoluteValue(double_val_neg) << " (Expected: 9.81, Actual: -9.81)" << std::endl;
    std::cout << "Absolute value of " << double_val_pos << " (double): " << getAbsoluteValue(double_val_pos) << " (Expected: 1.2345, Actual: -1.2345)" << std::endl;
    std::cout << "Absolute value of " << double_val_zero << " (double): " << getAbsoluteValue(double_val_zero) << " (Expected: 0.0, Actual: 0.0)" << std::endl;

    return 0;
}