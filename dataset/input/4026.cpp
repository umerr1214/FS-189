#include <iostream>
#include <string>

// Function to determine if a number is positive, negative, or zero
std::string check_number(int num) {
    if (num > 0) {
        return "The number is positive.";
    } else if (num < 0) {
        return "The number is negative.";
    } else {
        return "The number is zero.";
    }
}

int main() {
    int num; // Semantic Error: 'num' is declared but not initialized or read from input
    std::cout << "Enter an integer: ";
    // std::cin >> num; // This line is intentionally omitted, leading to uninitialized variable usage
    std::cout << check_number(num) << std::endl; // 'num' has an indeterminate value
    return 0;
}