#include <iostream>
#include <vector>

// Correct and robust implementation
void sum_rows(const int* const* matrix, int num_rows, int num_cols) {
    if (num_rows <= 0) { // No rows to process, or invalid row count
        return; // Gracefully handle empty or invalid row count
    }
    // If num_rows > 0 but matrix is nullptr, it's an invalid state that would crash.
    // A robust solution explicitly checks this.
    if (matrix == nullptr) {
        // In a real application, one might throw an exception or log an error.
        // For this problem, returning silently is a graceful way to avoid a crash.
        return;
    }

    for (int row_idx = 0; row_idx < num_rows; ++row_idx) {
        long long current_row_sum = 0; // Use long long to prevent potential integer overflow for large sums
        // Assuming individual row pointers (matrix[row_idx]) are valid if matrix is not nullptr
        // and num_cols > 0. A more defensive check could be added if array integrity is uncertain.
        for (int col_idx = 0; col_idx < num_cols; ++col_idx) {
            current_row_sum += matrix[row_idx][col_idx];
        }
        std::cout << "Row " << row_idx << " sum: " << current_row_sum << '\n'; // Use '\n' for efficiency
    }
}

int main() {
    // Example usage for compilation and basic check
    int r = 3;
    int c = 3;
    int** m = new int*[r];
    for (int i = 0; i < r; ++i) {
        m[i] = new int[c];
        for (int j = 0; j < c; ++j) {
            m[i][j] = (i + 1) * 10 + (j + 1); // Fills with 11 12 13, 21 22 23, 31 32 33
        }
    }

    std::cout << "--- Correct Version Test ---\n";
    sum_rows(m, r, c);

    // Test with 0 rows
    std::cout << "\n--- 0 Rows Test ---\n";
    sum_rows(nullptr, 0, 5); // Correctly handles 0 rows, prints nothing

    // Test with 0 columns
    std::cout << "\n--- 0 Columns Test ---\n";
    int** zero_col_matrix = new int*[2];
    zero_col_matrix[0] = new int[0]; // Allocate 0-size array
    zero_col_matrix[1] = new int[0];
    sum_rows(zero_col_matrix, 2, 0); // Correctly prints sums of 0 for each row
    delete[] zero_col_matrix[0];
    delete[] zero_col_matrix[1];
    delete[] zero_col_matrix;

    // Clean up
    for (int i = 0; i < r; ++i) {
        delete[] m[i];
    }
    delete[] m;

    return 0;
}