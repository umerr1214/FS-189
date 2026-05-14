#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;

void rotateMatrix(int matrix[][N], int n) {
    // Efficiency/Readability: Using O(N^2) extra space to create a new matrix
    // instead of O(1) in-place rotation.
    
    int temp[N][N];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }
    
    // Copy back
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateMatrix(matrix, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
