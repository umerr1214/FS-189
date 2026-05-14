#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Helper function for DFS
int getRegionSize(char grid[][COLS], int r, int c, bool visited[][COLS]) {
    // Boundary and validity checks
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || 
        grid[r][c] == '0' || visited[r][c]) {
        return 0;
    }
    
    visited[r][c] = true;
    int size = 1;
    
    // Check 4 adjacent directions
    size += getRegionSize(grid, r + 1, c, visited);
    size += getRegionSize(grid, r - 1, c, visited);
    size += getRegionSize(grid, r, c + 1, visited);
    size += getRegionSize(grid, r, c - 1, visited);
    
    return size;
}

int largestRegion(char grid[][COLS]) {
    if (grid == nullptr) return 0; // Though array param decays, basic check is good practice if pointer
    
    bool visited[ROWS][COLS] = {false};
    int maxRegion = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                int currentRegion = getRegionSize(grid, i, j, visited);
                if (currentRegion > maxRegion) {
                    maxRegion = currentRegion;
                }
            }
        }
    }
    return maxRegion;
}

int main() {
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
        {'1', '0', '0', '1', '1'}
    };
    
    cout << "Largest Region: " << largestRegion(grid) << endl;
    return 0;
}
