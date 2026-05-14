#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void transposeMatrix(char matrix[][COLS]) {
    cout << "Transpose:" << endl;
    for (int i = 0; i < COLS; i++) {
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
    
    transposeMatrix(matrix) // Syntax Error: Missing semicolon
    return 0;
}
