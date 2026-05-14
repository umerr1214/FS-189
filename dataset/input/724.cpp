#include <iostream>
using namespace std;

const int SIZE = 3;

void UpperHalf(int A[][SIZE], int N) {
    // Robustness Issue: No check if N exceeds SIZE.
    // If N > SIZE, we access out of bounds.
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Buffer overflow if N > SIZE
            if (j >= i) {
                cout << A[i][j] << " ";
            } else {
                cout << "  ";
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
    
    // Crash or Garbage
    // UpperHalf(A, 10);
    
    return 0;
}
