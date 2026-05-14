#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but common in C++ array problems.

int main() {
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));

    // Input matrix elements
    std::cout << "Enter 9 integer elements for the 3x3 matrix:" << std::endl // Syntax Error: Missing semicolon here
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate and print row sums
    for (int i = 0; i < 3; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 3; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of row " << i << ": " << rowSum << std::endl;
    }

    return 0;
}