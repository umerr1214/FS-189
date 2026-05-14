#include <iostream>

int main() {
    // Readability Issue: Using magic number 3 directly instead of a named constant.
    int a[3][3]; // Readability Issue: Non-descriptive variable names.
    int b[3][3];
    int c[3][3];

    std::cout << "Input A:" << std::endl; // Minimal prompt
    for (int i = 0; i < 3; ++i) { // Readability Issue: Non-descriptive loop variable names.
        for (int j = 0; j < 3; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Input B:" << std::endl; // Minimal prompt
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> b[i][j];
        }
    }

    // Sum
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print A (Readability Issue: Poor formatting)
    std::cout << "\nA:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl; // Newline after all elements of A

    // Print B (Readability Issue: Poor formatting)
    std::cout << "\nB:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << b[i][j] << " ";
        }
    }
    std::cout << std::endl; // Newline after all elements of B

    // Print C (Readability Issue: Poor formatting)
    std::cout << "\nC:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << c[i][j] << " ";
        }
    }
    std::cout << std::endl; // Newline after all elements of C

    return 0;
}