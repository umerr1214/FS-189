#include <iostream>
#include <vector>
using namespace std;

void applyFilter(const vector<vector<int>>& input, const vector<vector<int>>& filter, vector<vector<int>>& output) {
    // Robustness Issue: No checks for input dimensions.
    // If input is smaller than 3x3 (e.g. 2x2), m-2 is 0 or negative.
    // Vector resize with negative size throws bad_alloc or similar.
    // Loops i < m-1 might not run, but if m < 2, m-1 is negative? No, int comparison.
    // If m=1, m-2 = -1. resize(-1) is huge (unsigned size_t). Crash.
    
    int m = input.size();
    if (m == 0) return;
    int n = input[0].size();
    
    // Crash if m < 3 or n < 3 due to resize logic or loop bounds if handled poorly
    output.resize(m - 2, vector<int>(n - 2)); 
    
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sum = 0;
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
    vector<vector<int>> input(2, vector<int>(2)); // Too small
    vector<vector<int>> filter(3, vector<int>(3));
    vector<vector<int>> output;
    
    // Crash
    // applyFilter(input, filter, output);
    
    return 0;
}
