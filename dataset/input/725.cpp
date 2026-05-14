#include <iostream>
using namespace std;

const int SIZE = 3;

void UpperHalf(int A[][SIZE], int N) {
    // Efficiency/Readability: Iterating all N*N elements.
    // We can optimize the inner loop to start from 'i', visiting only upper half elements.
    // O(N^2) still, but half the iterations.
    // Iterating j=0..N and checking if(j>=i) is less efficient than j=i..N.
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) {
                cout << A[i][j] << " ";
            } else {
                cout << "  "; // Printing spaces to maintain shape is arguably a feature,
                // but if the task is just "print elements", we waste iterations.
                // Assuming task implies printing valid elements only or maintaining format?
                // Let's assume just printing the list of values.
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
    UpperHalf(A, SIZE);
    return 0;
}
