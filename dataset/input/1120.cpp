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

    // SYNTAX ERROR: Typo 'vecor' instead of 'vector'
    void setElement(int row, const std::vecor<int>& row_values) {
        if (row >= 0 && row < 2 && row_values.size() == 2) {
            for (int j = 0; j < 2; ++j) {
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
    m.setElement(0, 0, 5);

    std::vector<int> row_data = {10, 20};
    // This line will cause a compile-time error due to the typo in the Matrix::setElement signature
    m.setElement(1, row_data); 

    m.print();
    return 0;
}