#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0) {
            rows = 1; cols = 1; // Fallback to 1x1
            data.resize(rows, std::vector<int>(cols, 0));
            std::cerr << "Invalid matrix dimensions. Defaulting to 1x1." << std::endl;
            return;
        }
        data.resize(rows, std::vector<int>(cols));
    }

    // Getters for dimensions (useful for driver logic and demonstrating error)
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Method to input values
    void inputValues() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Method to display matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << (j == cols - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }

    // Overload + operator for matrix addition (contains semantic error)
    Matrix operator+(const Matrix& other) const {
        // SEMANTIC ERROR: No dimension check for 'other' matrix before accessing its elements.
        // It implicitly assumes 'other' has at least the same dimensions as 'this' matrix.
        // If 'other.rows' or 'other.cols' are smaller than 'this.rows' or 'this.cols',
        // accessing 'other.data[i][j]' will result in out-of-bounds access (undefined behavior).
        
        Matrix result(rows, cols); // Result matrix takes dimensions of 'this'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j]; // Potential out-of-bounds access on 'other.data'
            }
        }
        return result;
    }
}; // Correct semicolon

int main() {
    int r1, c1, r2, c2;

    // Read dimensions for Matrix 1
    std::cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.inputValues();

    // Read dimensions for Matrix 2
    std::cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.inputValues();

    // The operator+ will be called even if dimensions mismatch, potentially leading to a crash.
    Matrix m3 = m1 + m2; 

    m3.display(); // Display the result matrix (may be garbage or program might have crashed)

    return 0;
}