#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int n; // Descriptive variable name for height

    // Robust input validation loop: Ensures 'n' is a positive integer
    while (true) {
        std::cout << "Enter the height of the pyramid (a positive integer): ";
        std::cin >> n;

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear the error flags
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (n <= 0) { // Check for non-positive integer
            std::cout << "Height must be a positive integer. Please try again." << std::endl;
        } else {
            // Input is valid, break out of the loop
            break;
        }
    }

    // Print the pyramid pattern
    // Outer loop iterates for each row, from 1 to n (inclusive)
    for (int i = 1; i <= n; ++i) {
        // Inner loop prints leading spaces for alignment
        // Number of spaces decreases with each row
        for (int j = 0; j < n - i; ++j) {
            std::cout << " ";
        }
        // Inner loop prints asterisks
        // Number of asterisks is 2*i - 1 for row 'i'
        for (int k = 0; k < 2 * i - 1; ++k) {
            std::cout << "*";
        }
        std::cout << '\n'; // Use '\n' for efficiency (avoids flushing buffer)
    }

    return 0;
}