#include <iostream>

int main() {
    // Initialize a 3x3 integer matrix
    int matrix[3][3] = {
        {10, 20, 30},
        {15, 25, 35},
        {1, 2, 3}
    };

    // Calculate and print the sum of elements in each row
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum = matrix[i][j]; // Logical Error: rowSum is assigned, not accumulated
        }
        std::cout << "Sum of row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}