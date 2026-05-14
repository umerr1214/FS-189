#include <iostream>
using namespace std;

const int SIZE = 3;

int Trace(int data[][SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][i];
    }
    return sum
} // Syntax Error: Missing semicolon

int main() {
    int data[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Trace: " << Trace(data, SIZE) << endl;
    return 0;
}
