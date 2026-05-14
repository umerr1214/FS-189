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
                // Logical Error: Incorrect frequency update logic.
                // Instead of incrementing the count for the character, 
                // it sets the frequency equal to the loop index 'j' or something irrelevant.
                // Or maybe resets it every time.
                
                // Let's reset frequency to 1 every time we see it.
                // So it only tells us if a character exists (1) or not (0), not the count.
                freq[grid[i][j]] = 1;
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
    
    // Expected: l: ***
    // Actual: l: *
    characterHistogram(grid, ROWS);
    return 0;
}
