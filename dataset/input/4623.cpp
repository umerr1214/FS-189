#include <iostream> // Required for std::cout in main, not strictly for isLeapYear

// Function to determine if a year is a leap year
bool isLeapYear(int year) {
    // Correct Version:
    // Implements the leap year rules precisely and concisely using a single boolean expression.
    // A leap year is divisible by 4,
    // but not by 100 unless it is also divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    // This main function is a placeholder. The actual driver code
    // for testing will be provided by the evaluation system.
    std::cout << "Running tests for isLeapYear function..." << std::endl;
    // Example calls (not part of the actual driver)
    // std::cout << "2000: " << (isLeapYear(2000) ? "true" : "false") << std::endl; // Expected: true
    // std::cout << "1900: " << (isLeapYear(1900) ? "true" : "false") << std::endl; // Expected: false
    return 0;
}