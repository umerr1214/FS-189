#include <iostream>

void solve() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year; // No check for invalid input type (e.g., non-integer)

    // The core logic is correct for valid integer inputs
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << year << " is a leap year." << std::endl;
            } else {
                std::cout << year << " is not a leap year." << std::endl;
            }
        } else {
            std::cout << year << " is a leap year." << std::endl;
        }
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}