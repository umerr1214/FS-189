#include <iostream>
#include <vector>

int main() {
    // Create a 3x4 integer matrix
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Calculate and print the sum of elements for each individual row
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 4; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Row " << i << " sum: " << rowSum << std::endl // Missing semicolon here
    }

    return 0;
}