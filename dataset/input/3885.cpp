#include <iostream>

// Function containing the core logic of the program
void solve_leap_year_problem() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    // This program correctly implements the leap year rules using a concise
    // and highly readable boolean expression. It handles all valid positive
    // integer year inputs according to the specified rules effectively.
    // The expression directly translates the leap year rules into code.

    bool is_leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    if (is_leap_year) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
}

int main() {
    solve_leap_year_problem();
    return 0;
}