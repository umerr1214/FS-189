#include <iostream>

int main() {
    int matrix[3][3];
    long long sum = 0; // Use long long for sum to prevent potential overflow with large integer inputs

    std::cout << "Enter values for the 3x3 matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j]; // Robustness issue: No input validation.
                                      // If a non-integer is entered, cin will fail,
                                      // and subsequent reads might fail or lead to an infinite loop.
        }
    }

    // Calculate the sum of all elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
        }
    }

    std::cout << "Sum of all elements: " << sum << std::endl;

    return 0;
}