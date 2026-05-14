#include <iostream>

// Global matrix - generally not robust for larger, more complex systems
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main() {
    std::cout << "Calculating row sums:" << std::endl;
    // Non-robust: Magic number '3' used directly, if matrix size changes, this needs manual update
    for (unsigned int i = 0; i < 3; ++i) { // Using unsigned int without explicit bounds checks awareness
        int rowSum = 0;
        for (unsigned int j = 0; j < 3; ++j) { // Another magic number
            rowSum += matrix[i][j];
        }
        std::cout << "Row " << i << " sum: " << rowSum << std::endl;
    }

    std::cout << "Calculating column sums:" << std::endl;
    // Non-robust: More magic numbers, duplicated logic
    for (unsigned int j = 0; j < 3; ++j) { // Looping columns first
        int colSum = 0;
        for (unsigned int i = 0; i < 3; ++i) { // Looping rows second
            colSum += matrix[i][j];
        }
        std::cout << "Column " << j << " sum: " << colSum << std::endl;
    }

    return 0;
}