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
    
    // Logical Error: Only searching Right and Down, missing Left and Up directions.
    // This will underestimate region sizes if they curve back up or left.
    size += dfs(grid, r + 1, c, visited); // Down
    size += dfs(grid, r, c + 1, visited); // Right
    
    // Missing:
    // size += dfs(grid, r - 1, c, visited); // Up
    // size += dfs(grid, r, c - 1, visited); // Left
    
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
    // Example where Up/Left matters: U-shape or C-shape
    // 1 1 1
    // 1 0 1
    // 1 1 1
    // Correct size: 8.
    // If scanning top-left (0,0), it goes R, R (top row), D (right col), D (right col), ...
    // But if we start somewhere else or split, it might fail?
    // Actually, if we scan row by row, we hit (0,0) first.
    // DFS from (0,0) with only Down/Right:
    // (0,0)->(0,1)->(0,2)->(1,2)->(2,2) = 5 nodes.
    // (1,0) starts new DFS? But (1,0) is connected to (0,0).
    // If (0,0) DFS finishes, (1,0) is NOT visited.
    // So main loop calls DFS on (1,0).
    // (1,0)->(2,0)->(2,1). Size 3.
    // Total max found = 5. Correct is 8.
    
    char grid[ROWS][COLS] = {
        {'1', '1', '1', '0', '0'},
        {'1', '0', '1', '0', '0'},
        {'1', '1', '1', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
    // Expected: 8
    // Actual: 5 (Top-Right-Down path) because it can't go Left/Up to connect parts if traversal order splits them?
    // Actually, (0,0) connects to (0,1), (1,0).
    // DFS(0,0) -> calls DFS(0,1) (Right) and DFS(1,0) (Down).
    // So with Down/Right, it *can* reach everything reachable via Down/Right moves from (0,0).
    // But (1,0) -> (2,0) -> (2,1). (2,1) needs to go UP to (1,1)? No, (1,1) is 0.
    // Wait, (2,1) needs to go RIGHT to (2,2) (1).
    // (0,2) needs to go DOWN to (1,2) -> (2,2).
    // So simple shapes might work.
    // We need a shape where we MUST go Up or Left.
    // Example: Spiral or simple "U" where we start at one tip but can't reach the other without Up/Left?
    // If we start at top-left, we are fine for anything reachable by monotonic moves.
    // But "U" shape: (0,0)-(1,0)-(2,0)-(2,1)-(2,2)-(1,2)-(0,2).
    // Start (0,0). Go down to (2,0). Right to (2,2).
    // At (2,2), we need to go UP to (1,2) and then UP to (0,2).
    // Our logic fails to go UP. So (1,2) and (0,2) are not visited in this DFS call.
    // They will be visited later in main loop as separate region?
    // Yes. So Max Region will be split.
    
    cout << "Largest Region: " << largestRegion(grid) << endl;
    return 0;
}
