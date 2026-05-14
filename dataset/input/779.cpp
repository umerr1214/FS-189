#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void transposeMatrix(char matrix[][COLS]) {
    // Efficiency/Readability:
    // Creating a whole new 2D vector to store transpose and then print?
    // Printing can be done O(1) space. Storing takes O(N*M) space.
    
    vector<vector<char>> transposed(COLS, vector<char>(ROWS));
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "Transpose:" << endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cout << transposed[i][j] << " ";
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
    return 0;
}
