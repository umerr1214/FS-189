#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p) {
    // Initialize result matrix C to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }
    
    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    }; // 2x3
    
    int B[MAX][MAX] = {
        {7, 8},
        {9, 1},
        {2, 3}
    }; // 3x2
    
    int C[MAX][MAX];
    
    // Result should be 2x2
    multiplyMatrices(A, B, C, 2, 3, 2) // Syntax Error: Missing semicolon
    
    cout << "Result matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
