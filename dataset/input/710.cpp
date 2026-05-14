#include <iostream>
using namespace std;

const int SIZE = 3;

int Trace(int data[][SIZE], int n) {
    int sum = 0;
    // Logical Error: Incorrect loop or indexing for diagonal.
    // Let's sum the anti-diagonal instead? Or sum rows?
    // Let's sum the first row only.
    
    for (int i = 0; i < n; i++) {
        sum += data[0][i]; // Summing first row instead of diagonal data[i][i]
    }
    return sum;
}

int main() {
    int data[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // Expected Trace: 1+5+9 = 15
    // Actual: 1+2+3 = 6
    cout << "Trace: " << Trace(data, SIZE) << endl;
    return 0;
}
