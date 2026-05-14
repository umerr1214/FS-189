#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void transposeMatrix(char matrix[][COLS]) {
    if (matrix == nullptr) return;

    cout << "Transpose:" << endl;
    // Iterate columns of original matrix (rows of transpose)
    for (int i = 0; i < COLS; i++) {
        // Iterate rows of original matrix (cols of transpose)
        for (int j = 0; j < ROWS; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    char matrix[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'}
    };
    
    transposeMatrix(matrix);
    
    transposeMatrix(NULL); // Robustness test
    
    return 0;
}
