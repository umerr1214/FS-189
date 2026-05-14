#include <iostream>

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    bool is_leap_year;

    // Semantic error: Misuse of the comma operator in the first part of the OR condition.
    // The expression (year % 4 == 0 && year % 100 != 0, year % 400 == 0)
    // evaluates to the result of 'year % 400 == 0' because of the comma operator.
    // This effectively makes the condition: if (year % 400 == 0 || year % 400 == 0)
    // which simplifies to: if (year % 400 == 0).
    // The intended logic for divisibility by 4 and not by 100 is lost.
    if ((year % 4 == 0 && year % 100 != 0, year % 400 == 0) || (year % 400 == 0)) {
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