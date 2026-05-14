#include <iostream>

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    // Logical error: The condition for leap year is incomplete.
    // It correctly handles divisibility by 4 and not by 100,
    // but it misses the exception for years divisible by 400 (e.g., 2000).
    if (year % 4 == 0 && year % 100 != 0) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }

    return 0;
}