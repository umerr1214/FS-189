#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    if (n < 0) {
        // Robustness Issue: No explicit error message for negative input.
        // The program simply exits without output, which is not user-friendly.
        return 0;
    }

    if (n == 0) {
        // Prints nothing for n=0, which is functionally correct for "zero terms".
        return 0;
    }

    if (n == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // The Fibonacci numbers are stored in 'int' variables.
    // This is a Robustness Issue as 'int' can overflow for larger 'n' values
    // (e.g., n >= 47 on systems where int is 32-bit), leading to incorrect results.
    int a = 0;
    int b = 1;
    std::cout << a << " " << b;

    for (int i = 2; i < n; ++i) {
        int next = a + b; // Potential integer overflow here
        std::cout << " " << next;
        a = b;
        b = next;
    }
    std::cout << std::endl;

    return 0;
}