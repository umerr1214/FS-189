#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;

void UpperHalf(int A[][SIZE], int N) {
    if (N <= 0 || N > SIZE) {
        cout << "Invalid size." << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        // Print leading spaces for visual alignment (optional but good for "Upper Half" shape)
        for (int k = 0; k < i; k++) {
            cout << "  "; // Assume 2 chars width roughly
        }
        
        // Optimize loop to start from diagonal
        for (int j = i; j < N; j++) {
            cout << A[i][j] << " ";
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
    
    cout << "Upper Half:" << endl;
    UpperHalf(A, SIZE);
    
    cout << "Invalid:" << endl;
    UpperHalf(A, 10);
    
    return 0;
}
