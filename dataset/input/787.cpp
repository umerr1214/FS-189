#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void characterHistogram(char grid[][COLS], int rows) {
    int freq[256] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != '\0') {
                freq[grid[i][j]]++;
            }
        }
    }
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": ";
            for (int k = 0; k < freq[i]; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

int main() {
    char grid[ROWS][COLS] = {
        "hello",
        "world",
        "test"
    };
    
    characterHistogram(grid, ROWS) // Syntax Error: Missing semicolon
    return 0;
}
