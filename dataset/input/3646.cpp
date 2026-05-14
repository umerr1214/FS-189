#include <iostream>
#include <vector>

int main() {
    // Define two 3x3 integer matrices
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Declare a matrix to store the sum
    int resultMatrix[3][3];

    // Perform matrix addition
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) { // Missing semicolon after this line
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }

    // Print the resulting sum matrix
    std::cout << "Sum Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << resultMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}