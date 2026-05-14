#include <iostream>
using namespace std;

const int SIZE = 3;

int Trace(int data[][SIZE], int n) {
    // Efficiency/Readability Issue: Iterating entire matrix O(N^2) just to sum diagonal O(N).
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += data[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int data[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Trace: " << Trace(data, SIZE) << endl;
    return 0;
}
