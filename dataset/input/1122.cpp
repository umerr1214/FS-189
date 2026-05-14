#include <iostream>
#include <vector>

class Matrix {
private:
    int** mat; // Using dynamic allocation
    int rows;
    int cols;

public:
    Matrix(int r = 2, int c = 2) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    // SEMANTIC ERROR: Missing destructor to deallocate dynamically allocated 'mat'.
    // This will cause a memory leak when Matrix objects go out of scope.
    // Correct implementation would be:
    // ~Matrix() {
    //     for (int i = 0; i < rows; ++i) {
    //         delete[] mat[i];
    //     }
    //     delete[] mat;
    // }

    void setElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            mat[row][col] = value;
        }
    }

    void setElement(int row, const std::vector<int>& row_values) {
        if (row >= 0 && row < rows) {
            for (int j = 0; j < cols; ++j) {
                if (j < row_values.size()) {
                    mat[row][j] = row_values[j];
                } else {
                    mat[row][j] = 0; // Fill remaining with 0 if vector is shorter
                }
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Creating a matrix object, memory is allocated
    Matrix m(2, 2);
    m.setElement(0, 0, 1);
    m.setElement(0, 1, 2);
    m.setElement(1, 0, 3);
    m.setElement(1, 1, 4);

    std::cout << "Matrix content:" << std::endl;
    m.print();

    std::vector<int> new_row = {10, 20};
    m.setElement(0, new_row);
    std::cout << "\nMatrix after setting row 0:" << std::endl;
    m.print();

    // When 'm' goes out of scope, its dynamically allocated memory will not be properly deallocated
    // due to the missing destructor. This is a memory leak, a semantic error.
    return 0;
}