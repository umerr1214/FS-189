#include <iostream>
#include <algorithm> // Not strictly necessary for this simple implementation but good practice for max/min operations

// Develop a C++ function template `T findMax(T val1, T val2)`
// that accepts two values of any data type (`T`) and returns the larger of the two.
template <typename T>
T findMax(T val1, T val2) {
    // Using the ternary operator for a concise, clear, and efficient comparison.
    // This is the standard and most readable way to implement a simple max function.
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Demonstrate its usage in main

    // 1. Finding the maximum of two integers
    int num1_int = 10;
    int num2_int = 20;
    int max_int_result = findMax(num1_int, num2_int);
    std::cout << "The maximum of " << num1_int << " and " << num2_int << " is: " << max_int_result << std::endl; // Expected: 20

    // 2. Finding the maximum of two floating-point numbers
    double num1_float = 15.5;
    double num2_float = 15.0;
    double max_float_result = findMax(num1_float, num2_float);
    std::cout << "The maximum of " << num1_float << " and " << num2_float << " is: " << max_float_result << std::endl; // Expected: 15.5

    // Optional: Test with equal values to ensure correct behavior
    int num3_int = 7;
    int num4_int = 7;
    int max_equal_result = findMax(num3_int, num4_int);
    std::cout << "The maximum of " << num3_int << " and " << num4_int << " is: " << max_equal_result << std::endl; // Expected: 7

    return 0;
}