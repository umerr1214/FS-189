#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for manual sum, but often used

int main() {
    // Initialize a 3x3 integer matrix
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Calculate and print the sum of elements in each row
    // Robustness issue: Hardcoding '3' for iteration bounds instead of using
    // matrix.size() and matrix[i].size(). While it works for the current
    // initialization, it makes the code fragile and non-robust if the
    // vector's actual dimensions were to change, potentially leading to
    // out-of-bounds access or incorrect calculations.
    for (int i = 0; i < 3; ++i) { // Hardcoded row count
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) { // Hardcoded column count
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of Row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}