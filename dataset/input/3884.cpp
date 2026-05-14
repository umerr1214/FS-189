#include <iostream>

// Function containing the core logic of the program
void solve_leap_year_problem() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    // This code implements the correct leap year logic,
    // but uses a deeply nested if-else structure. This approach,
    // while functionally correct, significantly reduces readability and
    // makes the code harder to follow compared to a single, clear boolean expression.
    // It also uses a redundant boolean variable 'is_leap' with multiple assignments.

    bool is_leap; // This variable is assigned multiple times within the nested structure.

    if (year % 4 == 0) { // Condition 1: Divisible by 4
        if (year % 100 == 0) { // Condition 2: Divisible by 100
            if (year % 400 == 0) { // Condition 3: Divisible by 400
                is_leap = true; // Divisible by 4, 100, and 400 (e.g., 2000)
            } else {
                is_leap = false; // Divisible by 4, 100, but not 400 (e.g., 1900)
            }
        } else {
            is_leap = true; // Divisible by 4 but not 100 (e.g., 2004)
        }
    } else {
        is_leap = false; // Not divisible by 4 (e.g., 2001)
    }

    if (is_leap) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
}

int main() {
    solve_leap_year_problem();
    return 0;
}