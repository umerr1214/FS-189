#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;

void rotateMatrix(int matrix[][N], int n) {
    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    
    rotateMatrix(matrix, N) // Syntax Error: Missing semicolon
    
    cout << "Rotated:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
