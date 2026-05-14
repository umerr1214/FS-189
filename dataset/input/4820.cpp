#include <iostream>

// Function to swap the values of two integers using the XOR swap algorithm.
// While technically efficient (no temporary variable), it is generally less
// readable and harder to understand for simple integer swaps compared to
// using a temporary variable.
void swapValues(int& a, int& b) {
    // Check if a and b refer to the same memory location to prevent self-swap issues
    // with XOR swap, though generally not an issue with distinct references.
    if (&a == &b) {
        return;
    }
    a = a ^ b; // a now holds the XOR sum of original a and b
    b = a ^ b; // b now holds (original a ^ original b) ^ original b = original a
    a = a ^ b; // a now holds (original a ^ original b) ^ original a = original b
}

int user_main() {
    int firstNum, secondNum; // Variable names are functional but could be more descriptive.

    std::cout << "Please input the first integer: ";
    std::cin >> firstNum;
    
    std::cout << "Please input the second integer: ";
    std::cin >> secondNum;

    std::cout << "Original values: firstNum = " << firstNum << ", secondNum = " << secondNum << std::endl;

    swapValues(firstNum, secondNum);

    std::cout << "Swapped values: firstNum = " << firstNum << ", secondNum = " << secondNum << std::endl;

    return 0;
}