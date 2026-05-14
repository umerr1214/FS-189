#include <iostream>
#include <vector>
using namespace std;

void applyFilter(const vector<vector<int>>& input, const vector<vector<int>>& filter, vector<vector<int>>& output) {
    int m = input.size();
    int n = input[0].size();
    
    output.resize(m - 2, vector<int>(n - 2));
    
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    // Logical Error: Incorrect indexing of filter
                    // filter indices should be 0, 1, 2.
                    // Here k+1, l+1 maps -1..1 to 0..2 correctly.
                    // BUT, let's use the WRONG indices for filter, e.g., fixed [1][1] or just k, l
                    
                    // Error: Using k, l directly (which are -1, 0, 1) as indices for filter
                    // This causes out of bounds (negative index) or accessing garbage
                    // Actually vector access with negative index is UB or throws in debug.
                    // Let's use a simpler logic error: Multiplies with input[i][j] (center) instead of neighbor
                    
                    sum += input[i][j] * filter[k + 1][l + 1]; // Logic Error: Always using center pixel
                }
            }
            output[i - 1][j - 1] = sum;
        }
    }
}

int main() {
    vector<vector<int>> input(5, vector<int>(5, 1)); // All 1s
    vector<vector<int>> filter(3, vector<int>(3, 1)); // All 1s
    
    vector<vector<int>> output;
    
    // Expected: Each pixel 9 (sum of 9 neighbors * 1)
    // Actual: Each pixel 9 (sum of 1 * 1 nine times) - Wait, if input is uniform, this logic error is hidden!
    // Let's use distinct input.
    
    // Input: Center 3x3 is all 2s.
    // Filter: All 1s.
    // Correct Convolution should pick up neighbors.
    // Logic Error: Uses center pixel 9 times.
    
    applyFilter(input, filter, output);
    return 0;
}
