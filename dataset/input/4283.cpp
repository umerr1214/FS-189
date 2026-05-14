#include <iostream>

const int MAX_COLS_FOR_FUNC = 10;

void sum_rows(int matrix[][MAX_COLS_FOR_FUNC], int num_rows, int num_cols) {
    // Logical Error: row_sum is initialized outside the outer loop.
    // It should be initialized inside the outer loop to reset for each new row.
    int row_sum = 0; 
    for (int i = 0; i < num_rows; ++i) {
        // Correct placement for row_sum initialization: int row_sum = 0;
        for (int j = 0; j < num_cols; ++j) {
            row_sum += matrix[i][j];
        }
        std::cout << "Sum for row " << i << ": " << row_sum << std::endl;
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