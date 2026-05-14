#include <iostream>

void solve() {
    // Declare and initialize a 3x3 integer 2D array (matrix)
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    long long totalSum = 0; // Using long long for sum to robustly handle potentially larger sums, good practice

    // Calculate the sum of all elements in the entire matrix
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            totalSum += matrix[row][col];
        }
    }

    // Print the sum of all elements
    std::cout << totalSum << std::endl;
}

int main() {
    solve();
    return 0;
}