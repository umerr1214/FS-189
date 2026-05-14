#include <iostream>
#include <string>

int main() {
    int N; // User-specified number of rows
    std::cout << "Enter the number of rows (N): ";
    std::cin >> N;

    // Input validation for a correct version
    if (N <= 0) {
        std::cout << "Number of rows must be a positive integer." << std::endl;
        return 1; // Indicate an error
    }

    // Correct Version: Uses clear variable names, standard loop structures,
    // and efficient newline printing.
    for (int row = 1; row <= N; ++row) { // Outer loop iterates from 1 to N for each row
        for (int col = 1; col <= row; ++col) { // Inner loop prints 'row' number of asterisks
            std::cout << "*";
        }
        std::cout << '\n'; // Use '\n' for efficient newline printing
    }

    return 0; // Program executed successfully
}