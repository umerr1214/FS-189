#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    int len = strlen(word);
    // Directions: Horizontal (Right), Vertical (Down), Diagonal (Down-Right)
    // dx changes row, dy changes col
    int dx[] = { 0, 1, 1 }; 
    int dy[] = { 1, 0, 1 };
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == word[0]) {
                for (int dir = 0; dir < 3; dir++) {
                    int k;
                    int rd = i + dx[dir];
                    int cd = j + dy[dir];
                    
                    for (k = 1; k < len; k++) {
                        // Logical Error: Incorrect bounds check (OR logic vs AND logic or simple mistake)
                        // This allows OOB access if check is loose, or fails prematurely.
                        // Or logic error in updating position.
                        
                        // Error: Failing to update rd, cd inside the loop!
                        // We check the *same* neighbor repeatedly.
                        if (rd < 0 || rd >= ROWS || cd < 0 || cd >= COLS || grid[rd][cd] != word[k]) {
                            break;
                        }
                        // Missing: rd += dx[dir]; cd += dy[dir];
                    }
                    
                    if (k == len) {
                        cout << "Found at (" << i << "," << j << ")" << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J'},
        {'K', 'L', 'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Y'}
    };
    // Looking for "GLQ". (Vertical)
    // G is at (1,1). L is at (2,1). Q is at (3,1).
    // The code checks neighbor (2,1) for 'L' (Correct).
    // Then it checks (2,1) AGAIN for 'Q' (Incorrect). grid[2][1] is 'L', word[2] is 'Q'. Mismatch.
    searchWord(grid, "GLQ"); 
    return 0;
}
