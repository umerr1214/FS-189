#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

int dfs(char grid[][COLS], int r, int c, bool visited[][COLS]) {
    // Semantic Error: Using bitwise operator on boolean/logic check?
    // Or maybe using assignment in array access?
    
    // Let's use the bitwise OR `|` instead of logical OR `||` in the boundary check.
    // if (r < 0 | r >= ROWS | c < 0 | c >= COLS) 
    // This is valid C++ (integral promotion of bools), but doesn't short-circuit.
    // If r is negative, accessing grid[r][c] (which might happen later) is bad.
    // But here we check bounds first.
    // Wait, if we use `|`, all conditions are evaluated.
    // If `r` is valid but `grid[r][c]` check is included?
    // `if (r < 0 | ... | grid[r][c] == '0')`
    // If r < 0 is true, `grid[r][c]` is STILL EVALUATED because `|` is not short-circuiting!
    // This causes OOB access/crash.
    
    if (r < 0 | r >= ROWS | c < 0 | c >= COLS | grid[r][c] == '0' | visited[r][c]) { // Semantic Error: No short-circuit
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
    return maxRegion;
}

int main() {
    char grid[ROWS][COLS] = {{'1'}};
    // DFS will call r-1 (-1).
    // `r < 0` is true. But `grid[-1][c]` is evaluated due to `|`.
    // Crash likely.
    largestRegion(grid);
    return 0;
}
