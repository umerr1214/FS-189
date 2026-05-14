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
                // Logical Error: Incorrect indices used for multiplication
                // Instead of A[i][k] * B[k][j], using A[i][j] * B[k][j]? 
                // Or A[i][k] * B[j][k]?
                // Let's use A[i][k] * B[j][k] (treating B as if it's transposed or just wrong index)
                
                // If B is 3x2, B[j][k] might be OOB if j >= 3 or k >= 2.
                // j goes up to p (2). k goes up to n (3).
                // So B[j][k] accesses B[0..1][0..2]. B is defined as [3][2].
                // Indices are within MAX bounds, but logically wrong.
                
                C[i][j] += A[i][k] * B[j][k]; // Wrong index for B
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
    
    // Expected C[0][0] = 1*7 + 2*9 + 3*2 = 7+18+6 = 31.
    // Actual C[0][0] with error (A[0][k] * B[0][k]):
    // k=0: 1 * 7 = 7
    // k=1: 2 * 8 = 16
    // k=2: 3 * (B[0][2]?? B is 3x2, so row 0 has cols 0,1. B[0][2] is next row start? or garbage?
    // In flat memory of 2D array [MAX][MAX], row 0 has 10 ints. So B[0][2] is 0 (initialized).
    // So 7+16+0 = 23.
    
    multiplyMatrices(A, B, C, 2, 3, 2);
    
    cout << "Result matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
