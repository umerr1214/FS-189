#include <iostream>
#include <limits> // Required for std::numeric_limits for input validation

int main() {
    int matrix[3][3];
    long long totalSum = 0; // Use descriptive variable name and long long to prevent potential overflow

    std::cout << "Welcome! Please enter the integer values for your 3x3 matrix.\n";

    // Loop to prompt for and read matrix elements with robust input validation
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << "Enter integer value for element at position [" << row << "][" << col << "]: ";
            // Input validation loop: ensures only valid integers are accepted
            while (!(std::cin >> matrix[row][col])) {
                std::cout << "Invalid input. Please enter an integer value: ";
                std::cin.clear(); // Clear the error flags on cin
                // Discard invalid input from the buffer up to the newline character
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    std::cout << "\nAll matrix elements have been entered successfully.\n";

    // Calculate the sum of all elements in the matrix
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            totalSum += matrix[row][col];
        }
    }

    std::cout << "The sum of all elements in the matrix is: " << totalSum << std::endl; // Use std::endl for flushing output

    return 0;
}