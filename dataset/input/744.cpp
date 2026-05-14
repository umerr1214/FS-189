#include <iostream>
#include <vector>
using namespace std;

void applyFilter(const vector<vector<int>>& input, const vector<vector<int>>& filter, vector<vector<int>>& output) {
    if (input.empty()) return;
    int m = input.size();
    int n = input[0].size();
    
    if (m < 3 || n < 3) {
        // Output cannot be formed as per "exclude boundary" rule for < 3x3
        output.clear();
        return; 
    }
    
    if (filter.size() != 3 || filter[0].size() != 3) {
        // Assume 3x3 filter required
        return;
    }
    
    // Pre-allocate output
    output.assign(m - 2, vector<int>(n - 2));
    
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sum = 0;
            // Apply 3x3 filter centered at (i, j)
            // Filter indices usually 0..2, mapping to offsets -1..1
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += input[i + k][j + l] * filter[k + 1][l + 1];
                }
            }
            output[i - 1][j - 1] = sum;
        }
    }
}

int main() {
    vector<vector<int>> input = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    vector<vector<int>> filter = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    
    vector<vector<int>> output;
    applyFilter(input, filter, output);
    
    cout << "Output:" << endl;
    for (const auto& row : output) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
