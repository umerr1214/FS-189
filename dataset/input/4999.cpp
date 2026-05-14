#include <iostream>
#include <vector> // Not strictly necessary for 3x3, but often used

int main() {
    // Declare a 3x3 integer matrix
    int matrix[3][3];
    const int ROWS = 3;
    const int COLS = 3;

    std::cout << "Enter " << ROWS * COLS << " integer elements for the 3x3 matrix:" << std::endl;

    // Read elements into the matrix
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "Enter element at matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
            // No input validation or error handling for cin failure
            // If non-integer input is provided, cin will enter a fail state,
            // subsequent reads will fail, and matrix elements might remain uninitialized
            // or contain garbage, leading to incorrect sums or unexpected behavior.
        }
    }

    std::cout << "\nMatrix elements:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nSum of elements for each row:" << std::endl;

    // Calculate and print the sum of elements for each row
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        for (int j = 0; j < COLS; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Row " << i << " Sum: " << rowSum << std::endl;
    }

    return 0;
}