#include <iostream>

int main() {
    std::cout << "Enter the height of the pyramid (a positive integer): ";
    int n;
    std::cin >> n;

    // Robustness issue: The program does not validate if 'n' is a positive integer.
    // If 'n' is 0 or negative, the loops will not execute, resulting in no pyramid
    // being printed, without any error message or re-prompting.
    // It also does not handle non-numeric input, which would cause std::cin.fail()
    // and potentially lead to undefined behavior or an infinite loop if input buffer
    // is not cleared.
    
    for (int i = 1; i <= n; ++i) {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j) {
            std::cout << " ";
        }
        // Print asterisks
        for (int k = 0; k < 2 * i - 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}