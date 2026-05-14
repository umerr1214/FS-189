#include <iostream>
#include <string> // For potential string manipulation in test drivers, not directly used here.

// Function template definition with a syntax error: missing semicolon
template <typename T>
T getAbsoluteValue(T value)
{
    if (value < 0) {
        return -value // Syntax Error: missing semicolon here
    }
    return value;
}

int main() {
    // This program is expected to fail compilation due to a syntax error
    // The calls below are commented out as they would prevent compilation.

    // int int_val = -5;
    // float float_val = -3.14f;
    // double double_val = 9.81;

    // std::cout << "Absolute value of " << int_val << ": " << getAbsoluteValue(int_val) << std::endl;
    // std::cout << "Absolute value of " << float_val << ": " << getAbsoluteValue(float_val) << std::endl;
    // std::cout << "Absolute value of " << double_val << ": " << getAbsoluteValue(double_val) << std::endl;

    std::cout << "This program contains a syntax error and will not compile." << std::endl;

    return 0;
}