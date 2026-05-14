#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void characterHistogram(char grid[][COLS], int rows) {
    if (rows <= 0) return;

    int freq[256] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != '\0') {
                unsigned char c = (unsigned char)grid[i][j];
                freq[c]++;
            }
        }
    }
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && isprint(i)) { // Print only printable characters for histogram
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
    
    characterHistogram(grid, ROWS);
    
    // Robustness test with negative char (if signed)
    char grid2[ROWS][COLS] = {{(char)255}}; 
    // Should be handled safely by unsigned cast
    characterHistogram(grid2, 1);
    
    return 0;
}
