#include <iostream>

int main() {
    int year;
    std::cout << "Enter a year: "
    std::cin >> year;

    bool is_leap_year;

    // A leap year is divisible by 4, but not by 100 unless it is also divisible by 400.
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
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