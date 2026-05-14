#include <iostream>

int main() {
    // Declare and initialize a 3x3 integer 2D array (matrix)
    int matrix[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    // Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
        }
    }

    // Print the sum
    std::cout << "Sum of all elements: " << sum << std::endl // Syntax Error: Missing semicolon
    return 0;
}