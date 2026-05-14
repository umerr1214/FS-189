#include <iostream>
#include <vector> // Not strictly needed for fixed size, but good practice for robustness sometimes

void solve() {
    // Declare and initialize a 3x3 integer 2D array (matrix)
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    long long totalSum = 0; // Use long long to prevent potential overflow, though not strictly needed for these small numbers

    // Calculate the sum of all elements in the entire matrix
    // ROBUSTNESS ISSUE: Off-by-one error in row loop condition.
    // This loop will only iterate for rows 0 and 1, missing row 2.
    for (int i = 0; i < 2; ++i) { // Should be i < 3
        for (int j = 0; j < 3; ++j) {
            totalSum += matrix[i][j];
        }
    }

    // Print the sum
    std::cout << totalSum << std::endl;
}

int main() {
    solve();
    return 0;
}