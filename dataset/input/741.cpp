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
                    // Semantic Error: Using comma operator in index?
                    // input[i, k] ? No, that's valid C++ (comma operator) but means input[k].
                    // input[i][j] is int.
                    
                    // Let's use assignment in array index?
                    // input[i = k][j] -> modifies loop var i.
                    
                    // Let's use bitwise shift instead of index?
                    
                    // Let's confuse value with index.
                    // sum += input[ filter[k+1][l+1] ][0]; // Using filter value as index for input
                    
                    // Or assigning to const input? Compile error.
                    
                    // Let's use:
                    if (input[i+k][j+l] = filter[k+1][l+1]) { // Semantic Error: Assignment instead of multiplication/usage
                        // This modifies 'input', but 'input' is const reference!
                        // Won't compile.
                        
                        // I need a semantic error that compiles.
                        // Comparison of addresses?
                        // &input[i][j] == &filter[...];
                        
                        // Let's remove const from signature to allow assignment error.
                    }
                }
            }
            output[i - 1][j - 1] = sum;
        }
    }
}

// Helper to allow compilation of assignment error (removing const)
void applyFilter_NonConst(vector<vector<int>>& input, vector<vector<int>>& filter, vector<vector<int>>& output) {
     int m = input.size();
    int n = input[0].size();
    output.resize(m - 2, vector<int>(n - 2));
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                     // Semantic: Assignment in expression where multiplication expected
                     // sum += (input[i+k][j+l] = filter[k+1][l+1]); 
                     // This modifies input matrix!
                     
                     // Or treating sum as pointer?
                     
                     // Let's assume user misuses the vector::at vs [] 
                     // Or uses size() as index.
                     
                     // Let's go with bitwise operator usage.
                     sum += input[i+k][j+l] ^ filter[k+1][l+1]; // XOR instead of multiply
                }
            }
            output[i - 1][j - 1] = sum;
        }
    }
}

int main() {
    return 0;
}
