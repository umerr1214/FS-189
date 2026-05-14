#include <iostream>

// Function to determine if a year is a leap year
bool isLeapYear(int year) {
    // Readability / Efficiency Issue:
    // This implementation uses a deeply nested if-else structure,
    // which, while logically correct, is less readable and more verbose
    // than a single boolean expression for this specific problem.
    // It requires more cognitive effort to parse the logic.
    // For this simple function, efficiency impact is minimal, but readability is reduced.
    
    if (year % 4 == 0) { // Divisible by 4
        if (year % 100 == 0) { // Divisible by 4 and by 100
            if (year % 400 == 0) { // Divisible by 4, by 100, and by 400
                return true;
            } else { // Divisible by 4, by 100, but not by 400
                return false;
            }
        } else { // Divisible by 4, but not by 100
            return true;
        }
    } else { // Not divisible by 4
        return false;
    }
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