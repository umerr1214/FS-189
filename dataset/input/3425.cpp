#include <iostream>

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    bool is_leap_year;

    // Incorrect logic: misses the condition for years divisible by 100 but not by 400
    // It will incorrectly classify years like 1900 as leap years.
    if (year % 4 == 0 || year % 400 == 0) {
        is_leap_year = true;
    } else {
        is_leap_year = false;
    }

    if (is_leap_year) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }

    return 0;
}