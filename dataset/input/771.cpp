#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    int len = strlen(word);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Semantic Error: Using array name `grid` as `int`?
            // Or maybe using `word` as char?
            
            // Let's compare `grid[i]` (row pointer) with `word` (string pointer).
            // if (grid[i] == word) // Compares address of row i with address of word
            
            // Let's use assignment in array index? 
            
            // Let's use the bitwise operator again on the whole word?
            // if (grid[i][j] & word) // Invalid operands
            
            // Let's assign word to grid?
            // grid[i][j] = word[0]; // Logic error (modifies grid), but valid syntax.
            
            // Let's try: treating character as string.
            // strstr(grid[i][j], word); // Error: char to char*
            
            // Let's use `strcmp` on a char?
            // strcmp(grid[i][j], "A"); // Error
            
            // Let's use the address of the char in grid:
            // if (strcmp(&grid[i][j], word) == 0)
            // This is semantically valid code (checks if substring starting at i,j matches word).
            // BUT it only checks horizontal words going right.
            // AND it assumes grid rows are null terminated strings? They are chars.
            // If they aren't null terminated, strcmp reads OOB.
            // This is a semantic error regarding C-strings vs char arrays.
            
            if (strncmp(&grid[i][j], word, len) == 0) { // Checks horizontal only
                 cout << "Found horizontal at " << i << "," << j << endl;
                 return true;
            }
            
            // If we only implement this, we miss vertical/diagonal.
            // Is that semantic or logical? It's logic.
            
            // Let's do something pointer-y.
            // Treating 2D array as 1D array of char*?
            // char** ptr = (char**)grid; // Invalid cast usually
            
            // Let's confuse column index with row index in accessing.
            // grid[j][i] ? Logical error.
            
            // Let's use `sizeof` on `word` parameter.
            // int wLen = sizeof(word); // Returns 4/8, not length of string.
            // Then loop `k < wLen`.
            
            // We'll go with `sizeof(word)` semantic error.
        }
    }
    return false;
}

bool searchWord_Semantic(char grid[][COLS], const char* word) {
    // Semantic Error: sizeof on pointer
    int len = sizeof(word); // Returns pointer size (e.g., 8), not string length
    // If word is "A", len is 8. We check 8 chars. Fails.
    // If word is "LONGSTRING", len is 8. Checks only 8. Fails.
    
    int dx[] = {0, 1}; 
    int dy[] = {1, 0};
    
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            for(int d=0; d<2; d++) {
                int k;
                for(k=0; k<len; k++) { // Loop runs fixed 8 times or 4 times
                    int r = i + k*dx[d];
                    int c = j + k*dy[d];
                    if(r>=ROWS || c>=COLS || grid[r][c] != word[k]) break;
                }
                if(k==len) return true;
            }
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS] = {{'A'}};
    searchWord_Semantic(grid, "A"); 
    return 0;
}
