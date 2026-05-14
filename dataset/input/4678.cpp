#include <iostream>
#include <vector>

long long calculateSum(const std::vector<std::vector<int>>& matrix) {
    long long totalSum = 0 // Syntax error: missing semicolon
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            totalSum += matrix[i][j];
        }
    }
    return totalSum;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    long long sum = calculateSum(matrix);
    std::cout << sum << std::endl;

    return 0;
}