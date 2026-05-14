#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N; // User input for the number of rows

    // Robustness Issue: Does not validate N.
    // If N is 0 or negative, the loops will simply not execute,
    // printing nothing, which is not robust error handling for invalid input.
    // A robust program would ideally inform the user or request valid input.

    for (int i = 1; i <= N; ++i) { // Outer loop for rows
        for (int j = 1; j <= i; ++j) { // Inner loop for columns (asterisks)
            std::cout << "*";
        }
        std::cout << std::endl; // New line after each row
    }

    return 0;
}