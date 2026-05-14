#include <iostream>

int main() {
    int matrix[3][3];
    long long sum = 0; // Using long long to potentially handle larger garbage values

    std::cout << "Enter values for the 3x3 matrix:" << std::endl;

    // Prompt user for matrix elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Calculate sum of all elements
    // Semantic error: Loop bounds are incorrect (i <= 3, j <= 3),
    // leading to out-of-bounds array access (matrix[3][...] and matrix[...][3]).
    // This results in undefined behavior, potentially summing garbage values or crashing.
    for (int i = 0; i <= 3; ++i) { // Incorrect loop condition
        for (int j = 0; j <= 3; ++j) { // Incorrect loop condition
            sum += matrix[i][j];
        }
    }

    // Print the sum
    std::cout << "Sum of all elements: " << sum << std::endl;

    return 0;
}