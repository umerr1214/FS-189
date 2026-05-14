#include <iostream>
#include <string>

// Readability / Efficiency Issue:
// 1. Efficiency: The function passes arguments by value (T arg1, T arg2). For large or complex
//    user-defined data types, this results in unnecessary copies, which can be inefficient.
//    Passing by const reference (const T&) is generally preferred for generic templates
//    to avoid copies. For fundamental types like int and double, the overhead is minimal.
// 2. Readability: The conditional logic is overly verbose, using an 'if-else if-else'
//    structure for a simple maximum comparison. A direct 'if-else' or the ternary operator
//    would be more concise and readable.
template <typename T>
T find_maximum(T arg1, T arg2) { // Efficiency issue: arguments passed by value
    T max_value_result;
    if (arg1 > arg2) {
        max_value_result = arg1;
    } else if (arg2 > arg1) { // Readability issue: redundant 'else if'
        max_value_result = arg2;
    } else { // Readability issue: redundant 'else' for equality, could be merged
        max_value_result = arg1; // If equal, either is fine.
    }
    return max_value_result;
}

int main() {
    // Test with int
    int num1 = 5;
    int num2 = 10;
    int max_int = find_maximum(num1, num2);
    std::cout << "Maximum of " << num1 << " and " << num2 << " (int): " << max_int << std::endl;

    // Test with double
    double val1 = 3.14;
    double val2 = 2.718;
    double max_double = find_maximum(val1, val2);
    std::cout << "Maximum of " << val1 << " and " << val2 << " (double): " << max_double << std::endl;

    return 0;
}