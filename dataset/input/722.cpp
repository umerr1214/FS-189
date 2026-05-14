#include <iostream>
using namespace std;

const int SIZE = 3;

void UpperHalf(int A[][SIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Logical Error: Incorrect condition for Upper Half
            // Upper half is j >= i.
            // This condition j <= i prints the Lower Half.
            if (j <= i) { 
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
    
    // Expected:
    // 1 2 3
    //   5 6
    //     9
    
    // Actual (Lower Half):
    // 1
    // 4 5
    // 7 8 9
    UpperHalf(A, SIZE);
    
    return 0;
}
