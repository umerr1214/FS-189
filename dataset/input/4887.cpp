#include <iostream>
#include <array> // Include <array> for std::array

// Function to calculate and print the sum of the main diagonal of a 4x4 matrix.
// This version is correct, readable, and efficient.
void calculateAndPrintDiagonalSum() {
    // Define matrix dimensions using a named constant for better readability and maintainability.
    // This makes the code flexible; changing MATRIX_SIZE here updates all relevant parts.
    const int MATRIX_SIZE = 4;

    // Initialize a 4x4 integer matrix using std::array for type safety, fixed size, and modern C++.
    std::array<std::array<int, MATRIX_SIZE>, MATRIX_SIZE> matrix = {{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }};

    int diagonalSum = 0; // Clear and descriptive variable name

    // Calculate the sum of elements along the main diagonal (top-left to bottom-right).
    // For a main diagonal, the row index 'i' is always equal to the column index 'j'.
    // A single loop is used, which is the most efficient approach for this task.
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        diagonalSum += matrix[i][i];
    }

    // Print the calculated sum with a clear and informative message.
    std::cout << "Sum of main diagonal elements: " << diagonalSum << std::endl;
}