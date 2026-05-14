#include <iostream>

void solve() {
    // Declare and initialize a 3x3 integer 2D array (matrix)
    int m[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // Cramped initialization
    long long s=0; // Short, uninformative variable names

    // Calculate the sum of all elements in the entire matrix
    for(int r=0;r<3;++r) { // Short variable names for row (r)
        for(int c=0;c<3;++c) { // Short variable names for column (c)
            s+=m[r][c]; // Dense code, lack of whitespace
        }
    }

    // Print the sum
    std::cout<<s<<std::endl; // Dense output
}

int main() {
    solve();
    return 0;
}