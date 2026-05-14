#include <iostream>
#include <vector>

// Function with robustness issues: no checks for null matrix or negative dimensions
void sum_rows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int current_row_sum = 0;
        for (int j = 0; j < cols; ++j) {
            // This access (matrix[i][j]) will cause a crash if 'matrix' is nullptr
            // or if 'rows' or 'cols' are negative, leading to out-of-bounds access
            // or infinite loops.
            current_row_sum += matrix[i][j];
        }
        std::cout << "Row " << i << " sum: " << current_row_sum << "\n";
    }
}

int main() {
    // Example usage for compilation and basic check
    int test_rows = 2;
    int test_cols = 3;
    int** test_matrix = new int*[test_rows];
    for (int i = 0; i < test_rows; ++i) {
        test_matrix[i] = new int[test_cols];
        for (int j = 0; j < test_cols; ++j) {
            test_matrix[i][j] = (i * test_cols) + j + 1; // Fills with 1 2 3, 4 5 6
        }
    }

    std::cout << "--- Valid Matrix Test ---\n";
    sum_rows(test_matrix, test_rows, test_cols);

    // Clean up
    for (int i = 0; i < test_rows; ++i) {
        delete[] test_matrix[i];
    }
    delete[] test_matrix;

    // The main function here will not trigger the robustness issues directly to ensure
    // compilation. The JSON driver will provide test cases that expose these issues.

    return 0;
}