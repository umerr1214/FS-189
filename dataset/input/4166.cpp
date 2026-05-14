#include <iostream>
#include <string> // Included for string literal usage in main for better output, not for getLarger

// Function template to get the larger of two comparable values
// Arguments are passed by value, which can be inefficient for large user-defined types.
template <typename T>
T getLarger(T val1, T val2) {
    T result; // Unnecessary temporary variable
    if (val1 > val2) {
        result = val1;
    } else {
        result = val2;
    }
    return result; // Returns by value, potentially another copy
}

int main() {
    std::cout << "--- Demonstrating getLarger function ---" << std::endl;

    // Demonstrate with int
    int num1 = 50;
    int num2 = 100;
    std::cout << "For integers " << num1 << " and " << num2 << ", the larger is: " << getLarger(num1, num2) << std::endl;

    std::cout << std::endl; // Separator for readability

    // Demonstrate with double
    double dval1 = 15.7;
    double dval2 = 15.70001;
    std::cout << "For doubles " << dval1 << " and " << dval2 << ", the larger is: " << getLarger(dval1, dval2) << std::endl;

    std::cout << std::endl; // Separator for readability

    // Another int example, demonstrating repetitive output style
    int a = -5;
    int b = -10;
    std::cout << "Comparing " << a << " and " << b << ": " << getLarger(a, b) << " is larger." << std::endl;

    std::cout << std::endl; // Separator for readability

    // Another double example
    double x = 0.001;
    double y = 0.0009;
    std::cout << "Comparing " << x << " and " << y << ": " << getLarger(x, y) << " is larger." << std::endl;

    std::cout << "--- End of demonstration ---" << std::endl;

    return 0;
}