#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    // Constructor - Robustness Issue: Allows non-positive dimensions, leading to a 0x0 matrix
    Matrix(int r, int c) {
        if (r <= 0 || c <= 0) {
            std::cout << "Warning: Matrix created with non-positive dimensions (" << r << "x" << c << "). Setting to 0x0.\n";
            rows = 0;
            cols = 0;
            // data remains empty
        } else {
            rows = r;
            cols = c;
            data.resize(rows, std::vector<int>(cols));
        }
    }

    // Method to input values
    void inputValues() {
        if (rows == 0 || cols == 0) {
            std::cout << "Cannot input values for an empty matrix.\n";
            return;
        }
        std::cout << "Enter " << rows << "x" << cols << " matrix values:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter value for [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Method to display matrix
    void display() const {
        if (rows == 0 || cols == 0) {
            std::cout << "Cannot display an empty matrix.\n";
            return;
        }
        std::cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }

    // Overload + operator - Robustness Issue: No dimension compatibility check for addition
    // This can lead to out-of-bounds access if 'other' matrix has smaller dimensions.
    Matrix operator+(const Matrix& other) const {
        if (this->rows == 0 || this->cols == 0 || other.rows == 0 || other.cols == 0) {
            std::cout << "Warning: Attempting to add matrices with zero dimensions. Returning empty matrix.\n";
            return Matrix(0, 0);
        }
        
        // CRITICAL ROBUSTNESS ISSUE: Assumes 'other' has at least 'this->rows' and 'this->cols'.
        // If other.rows < this->rows or other.cols < this->cols, 'other.data[i][j]' will access out of bounds.
        Matrix result(rows, cols); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // This line is prone to crash/undefined behavior if other's dimensions are smaller
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    // Scenario 1: Create a matrix with invalid dimensions
    Matrix m0(0, 3); // Will print warning, m0 becomes 0x0
    m0.inputValues(); // Will print "Cannot input values..."

    // Scenario 2: Add matrices with incompatible dimensions (triggers OOB in operator+)
    Matrix m1(2, 2);
    std::cout << "\nInput for Matrix 1 (2x2):\n";
    m1.inputValues(); // Input: 1 2 3 4

    Matrix m2(1, 1); // Smaller matrix, will cause OOB when added to m1
    std::cout << "\nInput for Matrix 2 (1x1):\n";
    m2.inputValues(); // Input: 5

    std::cout << "\nAttempting to add M1 (2x2) and M2 (1x1):\n";
    // This call will likely crash or produce garbage due to out-of-bounds access in operator+
    Matrix sum_mismatched = m1 + m2; // EXPECTED CRASH/UNDEFINED BEHAVIOR
    std::cout << "Result of mismatched addition (if program continues):\n";
    sum_mismatched.display(); // Will likely not be reached, or display garbage

    // Scenario 3: Add compatible matrices (should work fine)
    Matrix m3(2, 2);
    std::cout << "\nInput for Matrix 3 (2x2):\n";
    m3.inputValues(); // Input: 11 12 13 14
    
    std::cout << "\nAttempting to add M1 (2x2) and M3 (2x2):\n";
    Matrix sum_matched = m1 + m3;
    sum_matched.display();

    return 0;
}