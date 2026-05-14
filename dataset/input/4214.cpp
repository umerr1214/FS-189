#include <iostream>

int main() {
    int m1[3][3]; // Poor variable name for matrix 1
    int m2[3][3]; // Poor variable name for matrix 2
    int s[3][3];  // Poor variable name for sum matrix

    // Input for first matrix
    std::cout << "Enter 9 numbers for the first 3x3 matrix:\n";
    for (int r = 0; r < 3; ++r) { // Hardcoded dimension
        for (int c = 0; c < 3; ++c) {
            std::cin >> m1[r][c]; // Lack of specific prompts for each element
        }
    }

    // Input for second matrix
    std::cout << "Enter 9 numbers for the second 3x3 matrix:\n";
    for (int r = 0; r < 3; ++r) { // Hardcoded dimension
        for (int c = 0; c < 3; ++c) {
            std::cin >> m2[r][c]; // Lack of specific prompts for each element
        }
    }

    // Perform sum
    for (int r = 0; r < 3; ++r) { // Hardcoded dimension
        for (int c = 0; c < 3; ++c) {
            s[r][c] = m1[r][c] + m2[r][c]; // No comments for logic
        }
    }

    std::cout << "The sum matrix is:\n";
    // Display result
    for (int r = 0; r < 3; ++r) { // Hardcoded dimension
        for (int c = 0; c < 3; ++c) {
            std::cout << s[r][c] << " "; // Output format uses space, not tab for alignment
        }
        std::cout << "\n"; // Newline after each row
    }

    return 0;
}