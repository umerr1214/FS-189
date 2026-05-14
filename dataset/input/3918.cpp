#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    // Semantic error: Using `int` for Fibonacci numbers can lead to integer overflow
    // for large `n`, resulting in incorrect values.
    int a = 0, b = 1;

    if (n <= 0) {
        // Prints nothing for n <= 0
    } else if (n == 1) {
        std::cout << a << std::endl;
    } else {
        std::cout << a << " " << b;
        for (int i = 2; i < n; ++i) {
            int nextTerm = a + b; // Potential overflow here for large n
            std::cout << " " << nextTerm;
            a = b;
            b = nextTerm;
        }
        std::cout << std::endl;
    }
    return 0;
}