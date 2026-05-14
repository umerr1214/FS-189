#include <iostream>

// Constant for the maximum number of columns the function expects
// This is a common way to define a function that takes a 2D array
// The actual number of columns passed can be less than or equal to this.
const int MAX_COLS_FOR_FUNC = 10;

void sum_rows(int matrix[][MAX_COLS_FOR_FUNC], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; ++i) {
        int row_sum = 0;
        for (int j = 0; j < num_cols; ++j) {
            row_sum += matrix[i][j];
        }
        // Syntax Error: Missing semicolon after std::endl
        std::cout << "Sum for row " << i << ": " << row_sum << std::endl 
    }
}

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    sum_rows(matrix, ROWS, COLS);

    return 0;
}