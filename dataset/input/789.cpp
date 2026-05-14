#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void characterHistogram(char grid[][COLS], int rows) {
    int freq[256] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            // Semantic Error: Confusing character '0' with null terminator '\0'?
            // Or using assignment in if condition?
            // Or confusing the grid value with index?
            
            // Let's use assignment in `if` again, it's reliable.
            // if (grid[i][j] = 'a') // Sets everything to 'a'
            
            // Let's try treating the character as a pointer?
            // No.
            
            // Let's use:
            if (grid[i][j]) { // Valid check for non-null
                 // Semantic error: Using loop index `j` as the character to count?
                 // freq[j]++; 
                 // This counts column indices, not characters.
                 
                 // Better semantic error:
                 // freq[&grid[i][j]]++; // Trying to use address as index? Compile error.
                 
                 // How about:
                 // freq[grid[i]]++; // Error: grid[i] is char*
                 
                 // Let's stick to assignment in conditional:
                 if (grid[i][j] = ' ') { // Replaces everything with space
                     freq[' ']++;
                 } else {
                     freq[grid[i][j]]++;
                 }
            }
        }
    }
    
    // ...
}

void characterHistogram_Semantic(char grid[][COLS], int rows) {
    int freq[256] = {0};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            // Semantic Error: bitwise negation of char used as index?
            // freq[~grid[i][j]]++; // Valid but semantic nonsense (large negative index -> OOB)
            
            // Semantic Error: Using the address of the array as the frequency array?
            // grid[freq]++; // Type error
            
            // Let's use `sizeof` again? No.
            
            // Let's use:
            // freq[ grid[i][j] + "a" ] // Adding string literal pointer? Error.
            
            // Let's use assignment in array index?
            // freq[ grid[i][j] = 0 ]++; // Sets char to 0, increments freq[0]. 
            // Effectively clears the grid and counts nulls.
            freq[ grid[i][j] = 0 ]++; 
        }
    }
}

int main() {
    return 0;
}
