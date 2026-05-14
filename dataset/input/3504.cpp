#include <iostream>
#include <vector>

int main() {
    // Declare and initialize a 3x3 integer matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print the matrix in a formatted way (with a semantic error - out-of-bounds access)
    // The inner loop goes from 0 to 3, accessing matrix[i][3] which is out of bounds.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= 3; ++j) { // Semantic error: j goes out of bounds (0, 1, 2, 3)
            // Accessing matrix[i][3] leads to undefined behavior.
            // Depending on the compiler and runtime environment, this might print garbage, crash, or appear to work.
            if (j < 3) { // To prevent immediate crash for matrix[i][3] and print something for the 4th element
                std::cout << matrix[i][j] << " ";
            } else {
                std::cout << "ERR "; // Indicate out-of-bounds access with a placeholder
            }
        }
        std::cout << std::endl;
    }

    return 0;
}