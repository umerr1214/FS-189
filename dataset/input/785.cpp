#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

int dfs(char grid[][COLS], int r, int c, vector<pair<int, int>>& visitedList) {
    // Efficiency Issue: Using a vector `visitedList` and searching it linearly O(Size)
    // for every cell check.
    // Total complexity becomes O((N*M) * Size of Region).
    // In worst case (all 1s), checking visited is O(N*M), total O((N*M)^2).
    // Should use O(1) lookup like 2D bool array.
    
    for (auto p : visitedList) {
        if (p.first == r && p.second == c) return 0;
    }
    
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0') {
        return 0;
    }
    
    visitedList.push_back({r, c});
    int size = 1;
    
    size += dfs(grid, r + 1, c, visitedList);
    size += dfs(grid, r - 1, c, visitedList);
    size += dfs(grid, r, c + 1, visitedList);
    size += dfs(grid, r, c - 1, visitedList);
    
    return size;
}

int largestRegion(char grid[][COLS]) {
    vector<pair<int, int>> visitedList; // List of visited coordinates
    int maxRegion = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bool isVisited = false;
            for (auto p : visitedList) {
                if (p.first == i && p.second == j) {
                    isVisited = true;
                    break;
                }
            }
            
            if (grid[i][j] == '1' && !isVisited) {
                int currentRegion = dfs(grid, i, j, visitedList);
                maxRegion = max(maxRegion, currentRegion);
            }
        }
    }
    return maxRegion;
}

int main() {
    char grid[ROWS][COLS] = {{'1'}};
    cout << largestRegion(grid) << endl;
    return 0;
}
