#include <iostream>

int main() {
    // Initialize a 3x3 integer matrix
    int matrix[3][3] = {
        {10, 20, 30},
        {15, 25, 35},
        {1, 2, 3}
    };

    // Calculate and print the sum of elements in each row
    // Semantic Error: The loop condition `i <= 3` will cause an out-of-bounds access
    // when `i` becomes 3, as valid row indices are 0, 1, 2 for a 3x3 matrix.
    for (int i = 0; i <= 3; ++i) { 
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += matrix[i][j]; // Accesses matrix[3][j] when i=3, leading to undefined behavior
        }
        std::cout << "Sum of row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}