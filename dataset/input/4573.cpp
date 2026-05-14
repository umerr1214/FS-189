#include <iostream>
#include <iomanip> // Required for std::setw

// Define matrix dimensions
const int ROWS = 3;
const int COLS = 3;

int main() {
    // Declare a 3x3 matrix
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int scalarValue; // Scalar value is not initialized
    int resultMatrix[ROWS][COLS];

    // Prompt the user for a scalar value
    std::cout << "Enter a scalar value for multiplication: ";
    std::cin >> scalarValue; // No input validation or error handling

    // Perform scalar multiplication
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            resultMatrix[i][j] = matrix[i][j] * scalarValue;
        }
    }

    // Print the resulting matrix
    std::cout << "Matrix after scalar multiplication:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << resultMatrix[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}