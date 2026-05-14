#include <iostream>
#include <iomanip> // Required for std::setw
#include <limits>  // Required for std::numeric_limits

// Define matrix dimensions using constants for better readability and maintainability
const int ROWS = 3;
const int COLS = 3;

int main() {
    // Declare a 3x3 matrix with initial values
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int scalarValue;
    int resultMatrix[ROWS][COLS];

    // Prompt the user for a scalar value with basic input validation
    std::cout << "Enter a scalar value for multiplication: ";
    while (!(std::cin >> scalarValue)) {
        std::cout << "Invalid input. Please enter a numeric value: ";
        std::cin.clear(); // Clear the error flag
        // Ignore the rest of the invalid line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Perform scalar multiplication
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            resultMatrix[i][j] = matrix[i][j] * scalarValue;
        }
    }

    // Print the resulting matrix with clear formatting
    std::cout << "Matrix after scalar multiplication:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << resultMatrix[i][j];
        }
        std::cout << "\n"; // Use '\n' for efficiency
    }

    return 0;
}