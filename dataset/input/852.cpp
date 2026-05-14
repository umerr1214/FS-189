#include <iostream>
using namespace std;

const int COLS = 4;

void printSpiral(int matrix[][COLS], int rows, int cols) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) return;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        
        // Print right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        
        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int matrix[4][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    cout << "Spiral 4x4: ";
    printSpiral(matrix, 4, 4);
    
    int singleRow[1][COLS] = {{1, 2, 3, 4}};
    cout << "Spiral 1x4: ";
    printSpiral(singleRow, 1, 4);
    
    printSpiral(NULL, 0, 0); // Safe
    
    return 0;
}
