#include <iostream>

// Use constants for matrix dimensions for clarity and maintainability
const int MATRIX_ROWS = 4;
const int MATRIX_COLS = 3;

// Fixed matrix for the problem, clearly named
int matrix_data[MATRIX_ROWS][MATRIX_COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

// Function to calculate sum of elements in a specified row
// Includes robust bounds checking for the row index
int calculateRowSum(int row_index) {
    // Robustness: Check if the row_index is within valid bounds
    if (row_index < 0 || row_index >= MATRIX_ROWS) {
        // Return a special value to indicate an error, allowing the caller to handle it
        return -1; 
    }

    int sum = 0;
    for (int col = 0; col < MATRIX_COLS; ++col) {
        sum += matrix_data[row_index][col];
    }
    return sum;
}

int main() {
    int target_row_index;
    if (!(std::cin >> target_row_index)) {
        std::cerr << "Invalid input for row index." << std::endl;
        return 1;
    }

    int result_sum = calculateRowSum(target_row_index);

    // Handle the error indicator returned by the function
    if (result_sum == -1) { 
        std::cerr << "Error: Row index out of bounds." << std::endl;
        return 1;
    } else {
        std::cout << result_sum << std::endl;
    }

    return 0;
}