#include <iostream>
#include <vector>
#include <string> // Unused, but might be included for "readability" issues

// Global constant for matrix dimensions, but not used consistently
const int MATRIX_DIMENSION_ROW = 2;
const int MATRIX_DIMENSION_COL = 2;

class Matrix {
private:
    int m_data_arr[2][2]; // Fixed size 2x2 matrix, bad variable name

public:
    // Constructor with very explicit and verbose initialization
    Matrix() {
        m_data_arr[0][0] = 0;
        m_data_arr[0][1] = 0;
        m_data_arr[1][0] = 0;
        m_data_arr[1][1] = 0;
    }

    // Overloaded setElement method: sets a single element
    // Uses nested switch statements for basic bounds checking, which is inefficient and verbose
    void setElement(int r_idx, int c_idx, int val_to_set) { // Poor variable names
        bool row_ok = false;
        switch (r_idx) {
            case 0:
            case 1:
                row_ok = true;
                break;
            default:
                std::cerr << "Error: Invalid row index " << r_idx << " for single element set." << std::endl;
                return;
        }

        if (row_ok) {
            switch (c_idx) {
                case 0:
                case 1:
                    m_data_arr[r_idx][c_idx] = val_to_set;
                    break;
                default:
                    std::cerr << "Error: Invalid column index " << c_idx << " for single element set." << std::endl;
                    return;
            }
        }
    }

    // Overloaded setElement method: sets an entire row
    // Uses a while loop and manual increment, and checks size in a less direct way.
    void setElement(int r_index, const std::vector<int>& row_values_container) { // Poor variable names
        if (r_index < 0 || r_index >= MATRIX_DIMENSION_ROW) { // Uses constant, but still verbose check
            std::cerr << "Error: Invalid row index " << r_index << " for row set." << std::endl;
            return;
        }

        if (row_values_container.size() != MATRIX_DIMENSION_COL) { // Uses constant
            std::cerr << "Warning: Row values size mismatch for row " << r_index << ". Expected " << MATRIX_DIMENSION_COL
                      << ", got " << row_values_container.size() << ". Setting partial row." << std::endl;
        }

        unsigned int current_col_pos = 0; // Inefficient loop structure
        while (current_col_pos < row_values_container.size() && current_col_pos < MATRIX_DIMENSION_COL) {
            m_data_arr[r_index][current_col_pos] = row_values_container[current_col_pos];
            current_col_pos++;
        }
    }

    // Method to print the matrix for verification
    void print_the_matrix() const { // Poor method name
        for (int i_row = 0; i_row < 2; ++i_row) { // Uses magic number 2
            for (int j_col = 0; j_col < 2; ++j_col) { // Uses magic number 2
                std::cout << m_data_arr[i_row][j_col] << (j_col == 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix myMatrix; // Poor object name
    std::cout << "Initial Matrix (readability issue):" << std::endl;
    myMatrix.print_the_matrix(); // Expected: 0 0\n0 0

    std::cout << "\nSetting element (0,0) to 5:" << std::endl;
    myMatrix.setElement(0, 0, 5);
    myMatrix.print_the_matrix(); // Expected: 5 0\n0 0

    std::cout << "\nSetting row 1 to {10, 20}:" << std::endl;
    myMatrix.setElement(1, {10, 20});
    myMatrix.print_the_matrix(); // Expected: 5 0\n10 20

    std::cout << "\nSetting element (0,1) to 9:" << std::endl;
    myMatrix.setElement(0, 1, 9);
    myMatrix.print_the_matrix(); // Expected: 5 9\n10 20

    std::cout << "\n--- Demonstrating Readability/Efficiency Issues ---" << std::endl;

    std::cout << "\nAttempting to set element (2,0) to 99 (invalid row):" << std::endl;
    myMatrix.setElement(2, 0, 99); // Should print error, matrix unchanged
    myMatrix.print_the_matrix(); // Expected: 5 9\n10 20

    std::cout << "\nAttempting to set row 0 with {100, 200, 300} (too many columns):" << std::endl;
    myMatrix.setElement(0, {100, 200, 300}); // Should print warning, set {100, 200}
    myMatrix.print_the_matrix(); // Expected: 100 200\n10 20

    std::cout << "\nAttempting to set row 1 with {40} (too few columns):" << std::endl;
    myMatrix.setElement(1, {40}); // Should print warning, set {40, 20} (partial update)
    myMatrix.print_the_matrix(); // Expected: 100 200\n40 20

    return 0;
}