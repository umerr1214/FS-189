#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void characterHistogram(char grid[][COLS], int rows) {
    // Robustness Issue: No NULL check (if passed as pointer).
    // Also, signed char as index -> negative index if extended ASCII.
    // buffer overflow if freq array is small (but it is 256).
    // What if rows > actual size?
    
    int freq[256] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != '\0') {
                freq[grid[i][j]]++; // Potential negative index if char is signed > 127
            }
        }
    }
    // ...
}

int main() {
    char grid[ROWS][COLS] = {{ (char)128 }}; // -128
    // characterHistogram(grid, ROWS); // Crash or OOB write
    return 0;
}
