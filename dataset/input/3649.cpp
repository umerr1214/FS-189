#include <iostream>

int main() {
    const int SIZE = 3;
    int matrixA[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[SIZE][SIZE];
    // Populating matrixB with a pattern that is correct for 3x3 but
    // the implicit formula might be less robust if SIZE were to change
    // without careful recalculation of the pattern logic.
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrixB[i][j] = 9 - (i * SIZE + j); // Example: 9 8 7, 6 5 4, 3 2 1
        }
    }

    int sumMatrix[SIZE][SIZE];

    // Perform matrix addition
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Print the resulting sum matrix
    std::cout << "Sum Matrix:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Robustness issue: Prints an extra space after the last element of each row.
            // This can cause issues for strict output parsing or appear untidy.
            std::cout << sumMatrix[i][j] << " ";
        }
        std::cout << "\n"; // Using '\n' is generally fine for efficiency here
    }

    return 0;
}