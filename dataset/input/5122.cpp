#include <iostream>

int main() {
    int matrix[3][3] // Missing semicolon here
    int sum = 0;

    std::cout << "Enter values for the 3x3 matrix:" << std::endl;

    // Prompt user for matrix elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Calculate sum of all elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
        }
    }

    // Print the sum
    std::cout << "Sum of all elements: " << sum << std::endl;

    return 0;
}