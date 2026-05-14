#include <iostream>
#include <vector>

int main() {
    // Declare and initialize a 3x3 integer matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print the matrix in a formatted way
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " " // Missing semicolon here
        }
        std::cout << std::endl;
    }

    return 0;
}