#include <iostream>

// Fixed matrix for the problem
const int MATRIX_ROWS = 4;
const int MATRIX_COLS = 3;
int global_matrix[MATRIX_ROWS][MATRIX_COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

// Function to sum elements of a specified row - LACKS ROBUSTNESS
// This function does not perform bounds checking for row_index.
// Accessing global_matrix[row_index] with an out-of-bounds index will lead to undefined behavior.
int sumRowElements(int row_index) {
    int row_sum = 0;
    // Robustness issue: No bounds checking for row_index
    for (int j = 0; j < MATRIX_COLS; ++j) {
        row_sum += global_matrix[row_index][j];
    }
    return row_sum;
}

int main() {
    int target_row;
    if (!(std::cin >> target_row)) {
        std::cerr << "Invalid input for row index." << std::endl;
        return 1;
    }

    // Calling the function which lacks robustness
    int result = sumRowElements(target_row);
    std::cout << result << std::endl;

    return 0;
}