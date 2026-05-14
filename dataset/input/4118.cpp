#include <iostream>

int main() {
    int m1[2][2]; // Matrix 1
    int m2[2][2]; // Matrix 2
    int r[2][2];  // Result matrix

    std::cout << "Input for matrix 1:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "m1[" << i << "][" << j << "]: ";
            std::cin >> m1[i][j];
        }
    }

    std::cout << "Input for matrix 2:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "m2[" << i << "][" << j << "]: ";
            std::cin >> m2[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            r[i][j] = m1[i][j] + m2[i][j];
        }
    }

    std::cout << "\nMatrix 1:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << m1[i][j] << " "; // Less clear spacing compared to tabs
        }
        std::cout << "\n";
    }

    std::cout << "\nMatrix 2:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nResult Matrix:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << r[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}