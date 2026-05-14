#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool searchWord(char grid[][COLS], const char* word) {
    int len = strlen(word);
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == word[0]) {
                for (int dir = 0; dir < 8; dir++) {
                    int k, rd = i + x[dir], cd = j + y[dir];
                    for (k = 1; k < len; k++) {
                        if (rd < 0 || rd >= ROWS || cd < 0 || cd >= COLS || grid[rd][cd] != word[k]) {
                            break;
                        }
                        rd += x[dir];
                        cd += y[dir];
                    }
                    if (k == len) {
                        cout << "Found at (" << i << "," << j << ") to (" << rd - x[dir] << "," << cd - y[dir] << ")" << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false
} // Syntax Error: Missing semicolon

int main() {
    char grid[ROWS][COLS] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J'},
        {'K', 'L', 'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Y'}
    };
    searchWord(grid, "HIM"); // Example word
    return 0;
}
