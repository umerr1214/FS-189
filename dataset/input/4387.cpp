#include <iostream>

int main() {
    int N = 0; // Initialize N to 0. If cin fails, N will retain this value.
    std::cout << "Enter the number of rows: ";
    std::cin >> N;

    // Robustness issue: No input validation for non-integer input or negative N.
    // If std::cin fails (e.g., user enters "abc"), N will retain its initialized value of 0.
    // The program proceeds without user feedback or error handling for invalid input.
    // If N is negative, the loops simply won't run, producing no output.
    // This isn't a crash, but it's a lack of robust input handling and user guidance.

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << '\n';
    }

    return 0;
}