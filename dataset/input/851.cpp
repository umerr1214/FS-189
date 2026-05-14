#include <iostream>
#include <vector>
using namespace std;

const int COLS = 4;

void printSpiral(int matrix[][COLS], int rows, int cols) {
    // Efficiency/Readability:
    // Recursive implementation for Spiral?
    // Recursion adds stack overhead O(N*M) worst case or O(min(N,M)) depth.
    // Iterative O(1) space is better.
    // Also, creating sub-vectors or copies would be very inefficient.
    // Let's implement a recursive version that passes by value or copies?
    // Or just standard recursion which is less efficient than loop here.
    
    if (rows <= 0 || cols <= 0) return;
    
    // Print top row
    for (int i = 0; i < cols; i++) cout << matrix[0][i] << " ";
    
    // Recursive call on submatrix?
    // This requires pointer arithmetic or slicing.
    // Difficult to do cleanly with raw arrays without helper function.
    // Let's implement a helper that takes bounds.
    // But recursion depth is the main issue.
    
    // Or we can construct a vector of the result and print it at end?
    // O(N*M) space.
    
    vector<int> result;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
    }
    
    for (int x : result) cout << x << " ";
    cout << endl;
}

int main() {
    int matrix[4][COLS] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printSpiral(matrix, 4, 4);
    return 0;
}
