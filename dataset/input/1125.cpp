#include <iostream>
#include <vector>
#include <stdexcept> // For robust error handling

class Matrix {
private:
    std::vector<std::vector<int>> mat; // Dynamic 2D array using std::vector

    const int ROWS = 2; // Constant for matrix rows
    const int COLS = 2; // Constant for matrix columns

    // Helper method for bounds checking
    bool isValidPosition(int row, int col) const {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

public:
    // Constructor to initialize the 2x2 matrix with zeros
    Matrix() : mat(ROWS, std::vector<int>(COLS, 0)) {}

    // Overloaded setElement method: sets a single element
    // Includes robust bounds checking
    void setElement(int row, int col, int value) {
        if (!isValidPosition(row, col)) {
            std::cerr << "Error: setElement(row, col, value) - Invalid position (" << row << ", " << col << "). Out of bounds." << std::endl;
            // Optionally throw std::out_of_range("Matrix index out of bounds");
            return;
        }
        mat[row][col] = value;
    }

    // Overloaded setElement method: sets an entire row
    // Includes robust bounds checking and size validation
    void setElement(int row, const std::vector<int>& rowValues) {
        if (row < 0 || row >= ROWS) {
            std::cerr << "Error: setElement(row, std::vector<int>) - Invalid row index " << row << ". Out of bounds." << std::endl;
            return;
        }
        if (rowValues.size() != COLS) {
            std::cerr << "Error: setElement(row, std::vector<int>) - Mismatch in row values count for row " << row
                      << ". Expected " << COLS << " elements, but received " << rowValues.size() << "." << std::endl;
            return;
        }

        for (int j = 0; j < COLS; ++j) {
            mat[row][j] = rowValues[j];
        }
    }

    // Method to print the matrix for verification
    void print() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << mat[i][j] << (j == COLS - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix matrix;
    std::cout << "Initial Matrix:" << std::endl;
    matrix.print(); // Expected: 0 0\n0 0

    std::cout << "\nSetting element (0,0) to 5:" << std::endl;
    matrix.setElement(0, 0, 5);
    matrix.print(); // Expected: 5 0\n0 0

    std::cout << "\nSetting row 1 to {10, 20}:" << std::endl;
    matrix.setElement(1, {10, 20});
    matrix.print(); // Expected: 5 0\n10 20

    std::cout << "\nSetting element (0,1) to 9:" << std::endl;
    matrix.setElement(0, 1, 9);
    matrix.print(); // Expected: 5 9\n10 20

    std::cout << "\n--- Demonstrating Correct Error Handling ---" << std::endl;

    std::cout << "\nAttempting to set element (2,0) to 99 (invalid row):" << std::endl;
    matrix.setElement(2, 0, 99); // Should print error, matrix unchanged
    matrix.print(); // Expected: 5 9\n10 20

    std::cout << "\nAttempting to set element (0,2) to 88 (invalid column):" << std::endl;
    matrix.setElement(0, 2, 88); // Should print error, matrix unchanged
    matrix.print(); // Expected: 5 9\n10 20

    std::cout << "\nAttempting to set row 0 with {100, 200, 300} (too many columns):" << std::endl;
    matrix.setElement(0, {100, 200, 300}); // Should print error, matrix unchanged
    matrix.print(); // Expected: 5 9\n10 20

    std::cout << "\nAttempting to set row 1 with {40} (too few columns):" << std::endl;
    matrix.setElement(1, {40}); // Should print error, matrix unchanged
    matrix.print(); // Expected: 5 9\n10 20

    std::cout << "\nSetting row 0 correctly to {1, 2}:" << std::endl;
    matrix.setElement(0, {1, 2});
    matrix.print(); // Expected: 1 2\n10 20

    return 0;
}