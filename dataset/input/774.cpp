#include <iostream>
#include <cstring>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    if (word == nullptr || strlen(word) == 0) return false;
    
    int len = strlen(word);
    
    // 8 directions: N, NE, E, SE, S, SW, W, NW
    int x[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int y[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            
            // Check if first char matches
            if (grid[i][j] != word[0]) continue;
            
            // Check all 8 directions
            for (int dir = 0; dir < 8; dir++) {
                int k;
                int rd = i + x[dir];
                int cd = j + y[dir];
                
                for (k = 1; k < len; k++) {
                    if (rd < 0 || rd >= ROWS || cd < 0 || cd >= COLS || grid[rd][cd] != word[k]) {
                        break;
                    }
                    rd += x[dir];
                    cd += y[dir];
                }
                
                if (k == len) {
                    cout << "Word found starting at (" << i << ", " << j << ") "
                         << "ending at (" << rd - x[dir] << ", " << cd - y[dir] << ")" << endl;
                    return true;
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
    
    cout << "Searching for HIM..." << endl;
    // H(1,2), I(1,3), M(2,2)? No. 
    // H(1,2), I(1,3). M is at (2,2). 
    // Is 'HIM' in there?
    // H(1,2), I(1,3), N(2,3) -> HIN
    // H(1,2), G(1,1), F(1,0) -> HGF
    // H(1,2), M(2,2), R(3,2) -> HMR
    // Let's try 'GLQ' (1,1)->(2,1)->(3,1).
    if (searchWord(grid, "GLQ")) {
        // Found
    } else {
        cout << "GLQ Not found" << endl;
    }
    
    searchWord(grid, "AFK"); // 0,0 -> 1,0 -> 2,0
    
    return 0;
}
