#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Robustness: Null check for grid? 
// Standard 2D array cannot be null unless passed as pointer.
// But let's assume we modify signature to `char** grid`?
// Or maybe recursion depth?
// For 5x5, recursion is fine. For 1000x1000, stack overflow.
// This is a robustness issue with DFS.
// The prompt says "2D character array", usually implying small scale or Heap allocation if huge.
// Let's stick to NULL check if we can pass it as pointer, or maybe buffer overflow if dims are dynamic.
// Let's use `char**` signature to demonstrate NULL check missing.

int dfs(char** grid, int r, int c, int rows, int cols, vector<vector<bool>>& visited) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0' || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    int size = 1;
    
    size += dfs(grid, r + 1, c, rows, cols, visited);
    size += dfs(grid, r - 1, c, rows, cols, visited);
    size += dfs(grid, r, c + 1, rows, cols, visited);
    size += dfs(grid, r, c - 1, rows, cols, visited);
    
    return size;
}

int largestRegion(char** grid, int rows, int cols) {
    // Robustness Issue: No NULL check for grid
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int maxRegion = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) { // Crash if grid is NULL or grid[i] is NULL
                int currentRegion = dfs(grid, i, j, rows, cols, visited);
                maxRegion = max(maxRegion, currentRegion);
            }
        }
    }
    return maxRegion;
}

int main() {
    // largestRegion(NULL, 5, 5); // Crash
    return 0;
}
