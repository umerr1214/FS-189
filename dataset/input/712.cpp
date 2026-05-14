#include <iostream>
using namespace std;

const int SIZE = 3;

// Robustness: What if n > SIZE? Buffer overflow.
// The parameter says `int data[][SIZE]`, but `n` (dimension) is passed separately.
// If n is larger than actual array size, we crash.

int Trace(int data[][SIZE], int n) {
    // Robustness Issue: No check if n exceeds SIZE (if we assume SIZE is the fixed capacity).
    // Or if data is NULL (but 2D array param cannot be NULL easily unless passed as pointer).
    // Let's change signature to int** to show NULL check missing, or just assume n is valid.
    // If signature is fixed `int data[][SIZE]`, we can't really pass NULL easily.
    
    // However, we CAN pass n > SIZE.
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][i]; // Overflow if i >= SIZE
    }
    return sum;
}

int main() {
    int data[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // Buffer overflow reading
    cout << "Trace: " << Trace(data, 10) << endl; 
    return 0;
}
