#include <iostream>
#include <limits> // Required for std::numeric_limits

void solve() {
    int year;
    std::cout << "Enter a year: ";

    // Robust input handling: ensure the user enters a valid integer
    while (!(std::cin >> year)) {
        std::cout << "Invalid input. Please enter an integer year: ";
        std::cin.clear(); // Clear the error flag on std::cin
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Determine if it's a leap year based on the definition:
    // Divisible by 4, but not by 100 unless it is also divisible by 400.
    bool is_leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    if (is_leap_year) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}