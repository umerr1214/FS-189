#include <iostream>
#include <vector>

class Matrix {
private:
    int mat[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    void setElement(int row, int col, int value) {
        if (row >= 0 && row < 2 && col >= 0 && col < 2) {
            mat[row][col] = value;
        }
    }

    void setElement(int row, const std::vector<int>& row_values) {
        if (row >= 0 && row < 2) {
            // LOGICAL ERROR: The loop condition 'j < row_values.size()'
            // means if row_values is smaller than the matrix row width (2),
            // it will not set the entire row, leaving some elements untouched.
            // It should iterate 'j < 2' to ensure the entire row is handled,
            // potentially filling with default values if row_values is too short.
            for (int j = 0; j < row_values.size(); ++j) { 
                mat[row][j] = row_values[j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix m;
    m.setElement(0, 0, 1);
    m.setElement(0, 1, 2);
    m.setElement(1, 0, 3);
    m.setElement(1, 1, 4);

    std::cout << "Initial Matrix:" << std::endl;
    m.print();
    std::cout << "---" << std::endl;

    // Test case 1: vector smaller than row size
    std::vector<int> partial_row = {10};
    m.setElement(0, partial_row); // Due to logical error, only mat[0][0] will be updated
    std::cout << "After setting row 0 with {10}:" << std::endl;
    m.print(); 

    std::cout << "---" << std::endl;

    // Test case 2: vector full size (this works correctly by chance)
    std::vector<int> full_row = {50, 60};
    m.setElement(1, full_row); 
    std::cout << "After setting row 1 with {50, 60}:" << std::endl;
    m.print(); 

    return 0;
}