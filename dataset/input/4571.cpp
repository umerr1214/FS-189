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
    int scalar;

    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Prompt user for scalar value
    std::cout << "Enter a scalar value: ";
    std::cin >> scalar;

    // Perform scalar multiplication (LOGICAL ERROR: performs addition instead of multiplication)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            resultMatrix[i][j] = matrix[i][j] + scalar; // Should be matrix[i][j] * scalar;
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