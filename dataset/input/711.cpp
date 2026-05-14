#include <iostream>
using namespace std;

const int SIZE = 3;

int Trace(int data[][SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // Semantic Error: Using pointer arithmetic incorrectly?
        // Or treating the row array as the value?
        
        // Let's try adding the address of the row
        // sum += (int)data[i]; // Semantic error: adding address
        
        // Let's use assignment in condition again? No.
        
        // Let's confuse column index with row index in a way that implies misunderstanding 2D arrays.
        // sum += data[i]; // data[i] is int*, so cannot add to int without cast.
        
        // Let's use `data[i][i]` but as an l-value in a weird way?
        // Or using `sizeof` again?
        
        // Let's cast the pointer to int and add it.
        // sum += (long long)&data[i][i]; // Adding addresses.
        
        // Or maybe using the value as an index?
        // sum += data[data[i][i]][0]; // Dangerous semantic misuse
        
        // Let's go with treating the array as 1D flat array with single index?
        // sum += data[i*n + i]; // Compile error: data is 2D
        
        // Let's try:
        sum += (int)data[i]; // Semantic error: treating row pointer as integer value
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
