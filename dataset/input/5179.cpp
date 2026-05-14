#include <iostream>
#include <string> // Included for std::string comparison in main, to highlight the robustness issue with const char*

// Develop a C++ function template `T findMax(T val1, T val2)`
// that accepts two values of any data type (`T`) and returns the larger of the two.
template <typename T>
T findMax(T val1, T val2) {
    // This template implementation correctly compares values for types that define
    // a meaningful operator>.
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Demonstrate its usage in main

    // 1. Finding the maximum of two integers
    int intA = 10;
    int intB = 20;
    int maxInt = findMax(intA, intB);
    std::cout << "Max of " << intA << " and " << intB << " is: " << maxInt << std::endl;

    // 2. Finding the maximum of two floating-point numbers
    double floatC = 15.5;
    double floatD = 15.0;
    double maxFloat = findMax(floatC, floatD);
    std::cout << "Max of " << floatC << " and " << floatD << " is: " << maxFloat << std::endl;

    // Robustness Issue Demonstration: Comparing C-style strings (char pointers)
    // The `findMax` template, when instantiated with `const char*`, will compare
    // the memory addresses of the string literals, not their lexicographical content.
    // This is a common pitfall leading to unexpected or non-deterministic results
    // for what a user typically means by "maximum string".
    const char* s1 = "apple";
    const char* s2 = "banana";
    const char* max_s_ptr = findMax(s1, s2); // Compares pointers, not string content
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" (by pointer comparison) is: \"" << max_s_ptr << "\"" << std::endl;

    // For comparison, demonstrating correct string comparison using std::string
    std::string str1 = "apple";
    std::string str2 = "banana";
    std::string max_str_obj = findMax(str1, str2); // Compares lexicographically due to std::string::operator>
    std::cout << "Max of \"" << str1 << "\" and \"" << str2 << "\" (using std::string) is: \"" << max_str_obj << "\"" << std::endl;

    return 0;
}