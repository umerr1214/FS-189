#include <iostream>

int main() {
    // Declare and initialize the first 3x3 matrix
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Declare and populate the second 3x3 matrix
    int m2[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m2[i][j] = 9 - (i * 3 + j); // Populates with 9 8 7, 6 5 4, 3 2 1
        }
    }

    // Declare the matrix to store the sum
    int m3[3][3];

    // Perform matrix addition
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Print the resulting sum matrix
    std::cout << "Sum Matrix:" << std::endl; // Uses std::endl, which flushes the buffer
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m3[i][j] << (j == 2 ? "" : " ");
        }
        std::cout << std::endl; // Efficiency issue: std::endl flushes the buffer on each row
    }

    return 0;
}