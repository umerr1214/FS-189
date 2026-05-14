#include <iostream>

int main() {
    int year; // 'year' is declared but not initialized
    std::cout << "Enter a year: ";
    // Semantic error: 'year' is used in the condition below before it receives input.
    // This results in undefined behavior as 'year' holds a garbage value.
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
    std::cin >> year; // Input happens AFTER the check, making the check operate on uninitialized data.

    return 0;
}