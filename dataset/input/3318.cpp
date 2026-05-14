#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    if (n == 1) {
        std::cout << "0" << std::endl;
        return 0;
    }

    if (n == 2) {
        std::cout << "0 1" << std::endl;
        return 0;
    }

    // Semantic Error: Using 'int' for Fibonacci numbers that can exceed its maximum value.
    // This will lead to integer overflow (undefined behavior) for larger 'n' values
    // (e.g., n >= 48, where F(47) exceeds typical 32-bit signed int max).
    int a = 0, b = 1; // Should be long long

    std::cout << a << " " << b;

    for (int i = 2; i < n; ++i) {
        int next = a + b; // Potential overflow here
        std::cout << " " << next;
        a = b;
        b = next;
    }
    std::cout << std::endl;

    return 0;
}