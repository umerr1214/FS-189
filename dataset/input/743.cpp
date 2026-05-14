#include <iostream>
#include <vector>
using namespace std;

void applyFilter(const vector<vector<int>>& input, const vector<vector<int>>& filter, vector<vector<int>>& output) {
    // Efficiency/Readability: 
    // Calculating sum using a separate function call for every pixel?
    // Or maybe re-allocating the output vector rows inside the loop?
    
    int m = input.size();
    if (m < 3) return;
    int n = input[0].size();
    if (n < 3) return;
    
    output.clear();
    
    for (int i = 1; i < m - 1; i++) {
        vector<int> row; // Allocation in loop
        for (int j = 1; j < n - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += input[i + k][j + l] * filter[k + 1][l + 1];
                }
            }
            row.push_back(sum); // Reallocation
        }
        output.push_back(row); // Copying row vector
    }
}

int main() {
    return 0;
}
