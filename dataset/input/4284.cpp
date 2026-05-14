#include <iostream>

const int MAX_COLS_FOR_FUNC = 10;

void sum_rows(int matrix[][MAX_COLS_FOR_FUNC], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; ++i) {
        int row_sum = 0;
        // Semantic Error: Loop condition uses j <= num_cols instead of j < num_cols.
        // This causes an out-of-bounds access for matrix[i][num_cols].
        for (int j = 0; j <= num_cols; ++j) { 
            row_sum += matrix[i][j];
        }
        std::cout << "Sum for row " << i << ": " << row_sum << std::endl;
    }
}

int main() {
    const int ROWS = 3;
    const int COLS = 4; // Actual number of columns is 4 (indices 0-3)
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    sum_rows(matrix, ROWS, COLS);

    return 0;
}