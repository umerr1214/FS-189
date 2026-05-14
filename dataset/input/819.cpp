#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p) {
    // Semantic Error: Assuming 2D arrays are pointers to pointers (int**)
    // and trying to dereference them incorrectly or cast them.
    
    // Let's try assignment in loop condition again? No.
    
    // Let's use `sizeof` on the array parameters to determine loop bounds?
    // This is a classic semantic error. The parameters m, n, p are ignored.
    
    int rowsA = sizeof(A) / sizeof(A[0]); // Returns size of pointer / size of row?
    // A is `int (*)[10]`. sizeof(A) is 4 or 8. sizeof(A[0]) is 4*10 = 40.
    // Result is 0. Loop doesn't run.
    
    // Let's use this error.
    
    for (int i = 0; i < rowsA; i++) { // Loop condition i < 0 is false immediately.
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX] = {{1}};
    int B[MAX][MAX] = {{1}};
    int C[MAX][MAX] = {{0}};
    
    multiplyMatrices(A, B, C, 1, 1, 1);
    
    cout << "Result: " << C[0][0] << endl; // Should be 1, but is 0 because loop didn't run.
    return 0;
}
