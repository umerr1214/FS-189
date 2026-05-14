#include <iostream>

int main() {
    // Declare and initialize a 2x2 integer 2D array (matrix)
    int matrix[2][2] = { // Semantic Error: Declared as 2x2, but question asks for 3x3
        {10, 20},
        {30, 40}
    };

    // Calculate the sum of all elements - loops iterate as if it's a 3x3 matrix
    int sum = 0;
    for (int i = 0; i < 3; ++i) { // Accesses matrix[2][j] which is out-of-bounds
        for (int j = 0; j < 3; ++j) { // Accesses matrix[i][2] which is out-of-bounds
            sum += matrix[i][j]; // Undefined behavior due to out-of-bounds access
        }
    }

    // Print the sum
    std::cout << "Sum of all elements: " << sum << std::endl;
    return 0;
}