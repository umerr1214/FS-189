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

    // Overload + operator for matrix addition (contains logical error)
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Error: Matrices must have the same dimensions for addition." << std::endl;
            return Matrix(1,1); // Return a default 1x1 matrix on dimension mismatch
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] - other.data[i][j]; // LOGICAL ERROR: Performs subtraction instead of addition
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

    Matrix m3 = m1 + m2; // Perform matrix addition (will actually subtract)

    m3.display(); // Display the result matrix

    return 0;
}