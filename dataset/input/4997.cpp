#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));

    // Input matrix elements
    std::cout << "Enter 9 integer elements for the 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate and print row sums
    int rowSum = 0; // Logical Error: rowSum is declared outside the loop and not reset for each row
    for (int i = 0; i < 3; ++i) {
        // rowSum accumulates the sum of all previous rows as well
        for (int j = 0; j < 3; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}