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
        // Semantic error: Loop condition for column index j goes out of bounds (j <= 3 instead of j < 3)
        for (int j = 0; j <= 3; ++j) { // INCORRECT: Accesses matrix[i][3] which is out of bounds
            rowSum += matrix[i][j];
        }
        std::cout << rowSum << " ";
    }
    std::cout << std::endl;

    // Calculate and print the sum of elements for each column
    std::cout << "Column sums: ";
    for (int j = 0; j < 3; ++j) {
        int colSum = 0;
        for (int i = 0; i < 3; ++i) {
            colSum += matrix[i][j];
        }
        std::cout << colSum << " ";
    }
    std::cout << std::endl;

    return 0;
}