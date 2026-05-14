#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer 'n': ";
    std::cin >> n;

    // Robustness Issue: No explicit input validation for n <= 0.
    // The program silently produces no output for n <= 0, which is not user-friendly
    // given the problem statement implies 'n' is a positive integer.
    // It also does not provide an error message or guide the user for invalid input.

    if (n <= 0) {
        // No output, no error message. This is the robustness issue.
    } else if (n == 1) {
        std::cout << "0";
    } else { // n >= 2
        long long a = 0;
        long long b = 1;
        std::cout << a << " " << b;
        for (int i = 2; i < n; ++i) {
            long long next = a + b;
            std::cout << " " << next;
            a = b;
            b = next;
        }
    }
    std::cout << std::endl;

    return 0;
}