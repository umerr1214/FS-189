#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

int dfs(char grid[][COLS], int r, int c, bool visited[][COLS]) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0' || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    int size = 1;
    
    size += dfs(grid, r + 1, c, visited);
    size += dfs(grid, r - 1, c, visited);
    size += dfs(grid, r, c + 1, visited);
    size += dfs(grid, r, c - 1, visited);
    
    return size;
}

int largestRegion(char grid[][COLS]) {
    bool visited[ROWS][COLS] = {false};
    int maxRegion = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                int currentRegion = dfs(grid, i, j, visited);
                maxRegion = max(maxRegion, currentRegion);
            }
        }
    }
    return maxRegion
} // Syntax Error: Missing semicolon

int main() {
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
        {'1', '0', '0', '1', '1'} // Note: last row '1' is separate
    };
    
    cout << "Largest Region: " << largestRegion(grid) << endl;
    return 0;
}
