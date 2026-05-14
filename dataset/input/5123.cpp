#include <iostream>

int main() {
    int matrix[3][3];
    int sum; // Sum is declared but not initialized here

    std::cout << "Enter values for the 3x3 matrix:" << std::endl;

    // Prompt user for matrix elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element at [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Calculate sum of all elements
    // Logical error: sum is initialized inside the outer loop,
    // causing it to reset for each row and only store the sum of the last row.
    for (int i = 0; i < 3; ++i) {
        sum = 0; // Incorrect initialization point
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
        }
    }

    // Print the sum
    std::cout << "Sum of all elements: " << sum << std::endl;

    return 0;
}