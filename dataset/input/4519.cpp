#include <iostream>

// This program has a robustness issue:
// 1. It uses 'int' for Fibonacci terms, which will overflow for N greater than approximately 46.
// 2. It handles N <= 0 by returning 0, which is not an appropriate error handling for "Nth term"
//    (implying N is a positive integer) and provides incorrect output for N=0 or N<0.
int fibonacci(int n) {
    if (n <= 0) {
        // Incorrectly returns 0 for non-positive N.
        // The problem implies N is a positive integer.
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }

    int a = 1;
    int b = 1;
    int next; // This variable will store values that can exceed 'int' capacity.

    for (int i = 3; i <= n; ++i) {
        next = a + b; // Potential overflow for N > ~46
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int N;
    std::cin >> N;
    int result = fibonacci(N);
    std::cout << result << std::endl;
    return 0;
}