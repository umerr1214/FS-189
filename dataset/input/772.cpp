#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    // Robustness Issue: No NULL check for word.
    // strlen(NULL) crashes.
    
    int len = strlen(word); 
    
    // Also no bounds checking? (Implemented in loop usually)
    // But NULL word is key here.
    
    int x[] = { 0, 1 };
    int y[] = { 1, 0 };
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // ...
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS] = {{0}};
    // Crash
    // searchWord(grid, NULL);
    return 0;
}
