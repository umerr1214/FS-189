#include <iostream>
using namespace std;

const int SIZE = 3;

void UpperHalf(int A[][SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Semantic Error: Treating 2D array as 1D array incorrectly?
            // Or using assignment operator in condition?
            // Let's use assignment in condition.
            
            // Or perhaps confusing row index with value?
            
            // Let's try: `if (A[i] > A[j])` 
            // Comparing addresses of rows?
            // if (A[i] > A[j]) prints upper half based on memory addresses?
            // Since A[i] address increases with i, A[i] > A[j] is i > j (Lower half strict).
            // But we want upper half.
            
            // Let's use assignment:
            if (i = j) { // Semantic Error: Assigns j to i.
                // If j is non-zero, condition is true.
                // And loop variable i is modified! Infinite loop or chaos.
                cout << A[i][j] << " ";
            } else {
               // ...
            }
        }
        cout << endl;
    }
}

int main() {
    int A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Infinite loop or crash likely due to i being reset
    // UpperHalf(A, SIZE); 
    
    return 0;
}
