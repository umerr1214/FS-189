#include <iostream>

int main() {
    char N_char; // Semantic error: Reading input for N into a char
    std::cout << "Enter the number of rows: ";
    std::cin >> N_char;

    // Semantic error: Using the ASCII value of the character 'N_char' directly as
    // the integer number of rows, instead of converting it to its numeric value.
    // If user enters '4', N will be 52 (ASCII value of '4'), not 4.
    int N = N_char;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}