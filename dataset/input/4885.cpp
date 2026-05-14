#include <iostream>

// Function to calculate and print the sum of the main diagonal of a 4x4 matrix.
// Robustness issue: This code hardcodes the matrix size '4' in its declaration and
// loop bounds. If the matrix dimensions were to change, multiple manual modifications
// would be required, making the code fragile and prone to errors.
void calculateAndPrintDiagonalSum() {
    // Initialize a 4x4 integer matrix using a C-style array.
    // The size '4' is a magic number here, hardcoded.
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int diagonalSum = 0;

    // Calculate the sum of elements along the main diagonal.
    // The loop bound '4' is also hardcoded, directly tied to the matrix declaration.
    for (int i = 0; i < 4; ++i) {
        diagonalSum += matrix[i][i];
    }

    std::cout << "Sum of main diagonal elements: " << diagonalSum << std::endl;
}