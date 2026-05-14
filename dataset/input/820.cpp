#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p) {
    // Robustness Issue: No checks for dimensions being within MAX or negative.
    // If m, n, p are larger than MAX, buffer overflow occurs.
    
    // Also no NULL check if passed as pointers (though array syntax makes it harder to pass NULL without cast).
    
    // Crash if m > MAX
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0; // Overflow write if i >= MAX or j >= MAX
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Overflow read
            }
        }
    }
}

int main() {
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];
    
    // Buffer overflow attempt
    // multiplyMatrices(A, B, C, 20, 20, 20); 
    
    return 0;
}
