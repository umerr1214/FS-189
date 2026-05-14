#include <iostream>
#include <string> // Included for potential future use, not directly related to the current issue

// Develop a C++ function template `T findMax(T val1, T val2)`
// that accepts two values of any data type (`T`) and returns the larger of the two.
template <typename TypeParameterForComparison> // Overly verbose template parameter name
TypeParameterForComparison findMaximumValue(TypeParameterForComparison firstInputVal, TypeParameterForComparison secondInputVal) { // Overly verbose function and parameter names
    // Readability/Efficiency Issue: Overly verbose and slightly inefficient logic
    // instead of a simple, concise ternary operator.

    TypeParameterForComparison finalResultHolder; // Unnecessary temporary variable to hold the result

    // Redundant boolean variables and comparisons
    bool isFirstValueStrictlyGreater = (firstInputVal > secondInputVal);
    bool isSecondValueStrictlyGreater = (secondInputVal > firstInputVal);

    if (isFirstValueStrictlyGreater) {
        finalResultHolder = firstInputVal;
    } else if (isSecondValueStrictlyGreater) { // This 'else if' is redundant; a simple 'else' would suffice
        finalResultHolder = secondInputVal;
    } else { // This block handles the case where firstInputVal == secondInputVal
        finalResultHolder = firstInputVal; // If equal, either can be returned
    }

    return finalResultHolder;
}

int main() {
    // Demonstrate its usage in main

    // 1. Finding the maximum of two integers
    int integerOne = 10;
    int integerTwo = 20;
    int maxIntegerResult = findMaximumValue(integerOne, integerTwo);
    std::cout << "Maximum value of " << integerOne << " and " << integerTwo << " is: " << maxIntegerResult << std::endl;

    // 2. Finding the maximum of two floating-point numbers
    double floatValOne = 15.5;
    double floatValTwo = 15.0;
    double maxFloatResult = findMaximumValue(floatValOne, floatValTwo);
    std::cout << "Maximum value of " << floatValOne << " and " << floatValTwo << " is: " << maxFloatResult << std::endl;

    // Test with equal values to cover the 'else' branch
    int equalIntegerA = 5;
    int equalIntegerB = 5;
    int maxEqualIntegerResult = findMaximumValue(equalIntegerA, equalIntegerB);
    std::cout << "Maximum value of " << equalIntegerA << " and " << equalIntegerB << " is: " << maxEqualIntegerResult << std::endl;

    return 0;
}