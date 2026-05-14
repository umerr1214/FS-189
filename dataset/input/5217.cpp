#include <iostream>
#include <vector>
#include <stdexcept> // For std::invalid_argument

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    // Constructor: Validates dimensions for robustness
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0) {
            throw std::invalid_argument("Matrix dimensions must be positive.");
        }
        data.resize(rows, std::vector<int>(cols));
    }

    // Method to input values
    void inputValues() {
        std::cout << "Enter " << rows << "x" << cols << " matrix values:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter value for [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    // Method to display matrix: const-correct and efficient output
    void display() const {
        std::cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << '\n'; // Efficient newline character instead of std::endl
        }
    }

    // Overload + operator: Robust, efficient, and const-correct
    Matrix operator+(const Matrix& other) const { // Efficient: 'other' passed by const reference to avoid copy
        // Robustness: Check for compatible dimensions before performing addition
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions mismatch for addition.");
        }

        Matrix result(rows, cols); // Clear variable name
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Getters for dimensions (good practice for controlled external access)
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    // Demonstrate robust error handling with try-catch blocks
    try {
        // Scenario 1: Attempt to create matrix with invalid dimensions
        std::cout << "--- Attempting to create matrix with invalid dimensions ---\n";
        Matrix m_invalid(0, 3); // This will throw an exception
        m_invalid.display(); // This line won't be reached
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    std::cout << "\n--- Demonstrating valid matrix operations ---\n";
    Matrix m1(2, 2);
    std::cout << "Input for Matrix 1 (2x2):\n";
    m1.inputValues(); // Input: 1 2 3 4

    Matrix m2(2, 2);
    std::cout << "\nInput for Matrix 2 (2x2):\n";
    m2.inputValues(); // Input: 5 6 7 8

    std::cout << "\nAdding M1 and M2:\n";
    Matrix sum = m1 + m2; // Efficient: m2 passed by const reference
    sum.display(); // Efficient: sum passed by const reference, uses '\n'

    // Scenario 2: Attempt to add matrices with incompatible dimensions
    try {
        std::cout << "\n--- Attempting to add matrices with incompatible dimensions ---\n";
        Matrix m3(2, 3); // Different column count
        std::cout << "Input for Matrix 3 (2x3):\n";
        m3.inputValues(); // Input: 9 10 11 12 13 14

        std::cout << "\nAdding M1 (2x2) and M3 (2x3):\n";
        Matrix sum_mismatched = m1 + m3; // This will throw an exception
        sum_mismatched.display(); // This line won't be reached
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}