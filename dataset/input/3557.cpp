#include <iostream>

void transposeMatrix(int matrix[3][3], int result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i][j] = matrix[i][j]; // Logical Error: Copies the original matrix instead of transposing
        }
    }
}

void printMatrix(const int mat[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << mat[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    int originalMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transposedMatrix[3][3];

    transposeMatrix(originalMatrix, transposedMatrix);

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(originalMatrix);
    std::cout << "Transposed Matrix:" << std::endl;
    printMatrix(transposedMatrix);

    return 0;
}