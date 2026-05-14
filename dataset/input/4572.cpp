#include <iostream>
#include <vector>

int main() {
    // Declare a 3x3 matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int resultMatrix[3][3];
    int scalar; // Declared but not initialized or read from user input

    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // SEMANTIC ERROR: The program does not prompt for a scalar value,
    // and 'scalar' is used uninitialized, leading to undefined behavior.
    // The line 'std::cout << \"Enter a scalar value: \";' and 'std::cin >> scalar;' are missing.

    // Perform scalar multiplication using an uninitialized 'scalar'
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i][j] = matrix[i][j] * scalar; // 'scalar' holds a garbage value
        }
    }

    // Print the resulting matrix
    std::cout << "\nResulting Matrix after scalar multiplication:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << resultMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}