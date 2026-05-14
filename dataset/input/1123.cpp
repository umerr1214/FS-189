#include <iostream>
#include <vector>
#include <stdexcept> // Not actually used for robustness issue, but good practice

class Matrix {
private:
    int mat[2][2]; // Fixed size 2x2 matrix

public:
    // Constructor to initialize all elements to 0
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    // Overloaded setElement method: sets a single element
    // Lacks bounds checking, leading to robustness issues
    void setElement(int row, int col, int value) {
        // No bounds checking for row or col
        mat[row][col] = value;
    }

    // Overloaded setElement method: sets an entire row
    // Lacks bounds checking for row and assumes row_values.size() matches column count
    // If row_values.size() is different, it will cause out-of-bounds access or partial updates.
    void setElement(int row, const std::vector<int>& row_values) {
        for (int j = 0; j < row_values.size(); ++j) {
            // No bounds checking for row or j (column)
            // If row_values.size() > 2, it will write out of bounds for columns.
            // If row is out of bounds, it will crash.
            mat[row][j] = row_values[j];
        }
    }

    // Method to print the matrix for verification
    void print() const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << mat[i][j] << (j == 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix m;
    std::cout << "Initial Matrix:" << std::endl;
    m.print(); // Expected: 0 0\n0 0

    std::cout << "\nSetting element (0,0) to 5:" << std::endl;
    m.setElement(0, 0, 5);
    m.print(); // Expected: 5 0\n0 0

    std::cout << "\nSetting row 1 to {10, 20}:" << std::endl;
    m.setElement(1, {10, 20});
    m.print(); // Expected: 5 0\n10 20

    std::cout << "\nAttempting to set element (0,1) to 9:" << std::endl;
    m.setElement(0, 1, 9);
    m.print(); // Expected: 5 9\n10 20

    // Robustness Issue demonstration: Out-of-bounds access
    std::cout << "\n--- Demonstrating Robustness Issues ---" << std::endl;

    std::cout << "\nAttempting to set element (2,0) to 99 (out of bounds row):" << std::endl;
    // This will likely cause a segmentation fault or undefined behavior
    m.setElement(2, 0, 99); // CRASH/UNDEFINED BEHAVIOR EXPECTED HERE

    std::cout << "\nAttempting to set row 0 with {100, 200, 300} (too many columns):" << std::endl;
    // This will likely cause a segmentation fault or write to adjacent memory
    m.setElement(0, {100, 200, 300}); // CRASH/UNDEFINED BEHAVIOR EXPECTED HERE

    std::cout << "\nMatrix state after potential crashes (if program continued):" << std::endl;
    m.print(); // State is undefined if crashes occurred.
               // If it somehow continued, it would show corrupted data.

    return 0;
}