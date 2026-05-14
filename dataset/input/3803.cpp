#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Initialize a 3x3 integer matrix with hardcoded values
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Calculate and print the sum of elements for each row
    std::cout << "Row sums: ";
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << rowSum << " ";
    }
    std::cout << std::endl;

    // Calculate and print the sum of elements for each column
    // Logical error: The inner loop incorrectly sums matrix[j][j] instead of matrix[i][j]
    std::cout << "Column sums: ";
    for (int j = 0; j < 3; ++j) { // j iterates through columns
        int colSum = 0;
        for (int i = 0; i < 3; ++i) { // i iterates through rows
            colSum += matrix[j][j]; // INCORRECT: Should be matrix[i][j]
        }
        std::cout << colSum << " ";
    }
    std::cout << std::endl;

    return 0;
}