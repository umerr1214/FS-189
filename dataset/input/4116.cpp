#include <iostream>
#include <string>

using namespace std;

void printMatrix(const int matrix[2][2], const string& name) {
    cout << name << ":\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrix[i][j] << (j == 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    int matrix1[2][2];
    int matrix2[2][2];
    int result[2][2];

    cout << "Enter elements for Matrix 1 (2x2):\n";
    // Semantic Error: Loop goes out of bounds for a 2x2 matrix.
    // It will attempt to write to matrix1[2][0] and matrix1[2][1],
    // causing undefined behavior.
    for (int i = 0; i <= 2; ++i) { 
        for (int j = 0; j < 2; ++j) {
            cout << "Enter element M1[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements for Matrix 2 (2x2):\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Enter element M2[" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // Matrix Addition (this part is logically correct, but matrix1 might be corrupted)
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printMatrix(matrix1, "Matrix 1");
    printMatrix(matrix2, "Matrix 2");
    printMatrix(result, "Result Matrix");

    return 0;
}