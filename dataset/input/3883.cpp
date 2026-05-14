#include <iostream>
#include <string> // Included for general C++ program structure, though not strictly used for logic here.

// Function containing the core logic of the program
void solve_leap_year_problem() {
    int year = 0; // Initialize to 0. If input fails, 'year' will remain 0.
    std::cout << "Enter a year: ";
    std::cin >> year; // No input validation. This is the robustness issue.

    // The logic correctly determines if a given integer 'year' is a leap year.
    // However, the program lacks robustness in handling invalid input.
    // If the user enters non-numeric data (e.g., "abc"), `std::cin >> year` will fail,
    // `year` will retain its initialized value of 0, and the `cin` stream will enter a fail state.
    // Consequently, the program will incorrectly output "0 is a leap year."
    // It also does not explicitly validate for negative years, though the logic would apply mathematically.

    bool is_leap_year = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        is_leap_year = true;
    }

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