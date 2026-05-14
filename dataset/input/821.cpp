#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX = 10;

void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p) {
    // Efficiency/Readability:
    // Copying static arrays to vectors, multiplying, copying back?
    // Huge overhead for no reason.
    
    vector<vector<int>> vA(m, vector<int>(n));
    vector<vector<int>> vB(n, vector<int>(p));
    vector<vector<int>> vC(m, vector<int>(p));
    
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) vA[i][j] = A[i][j];
    for(int i=0; i<n; i++) for(int j=0; j<p; j++) vB[i][j] = B[i][j];
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<p; j++) {
            for(int k=0; k<n; k++) {
                vC[i][j] += vA[i][k] * vB[k][j];
            }
        }
    }
    
    for(int i=0; i<m; i++) for(int j=0; j<p; j++) C[i][j] = vC[i][j];
}

int main() {
    int A[MAX][MAX] = {{1, 2}, {3, 4}};
    int B[MAX][MAX] = {{1, 0}, {0, 1}};
    int C[MAX][MAX];
    multiplyMatrices(A, B, C, 2, 2, 2);
    return 0;
}
