#include <iostream>

// Function to swap the values of two integers using a temporary variable.
// This implementation is correct for swapping.
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int user_main() {
    int val1, val2;

    std::cout << "Enter first integer: ";
    std::cin >> val1; // Robustness issue: No input validation for non-integer input
    
    std::cout << "Enter second integer: ";
    std::cin >> val2; // Robustness issue: No input validation for non-integer input

    std::cout << "Before swap: a = " << val1 << ", b = " << val2 << std::endl;

    swapValues(val1, val2);

    std::cout << "After swap: a = " << val1 << ", b = " << val2 << std::endl;

    return 0;
}