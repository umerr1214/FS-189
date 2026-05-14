#include <iostream>

// Readability/Efficiency Issue: Naive recursive solution for Fibonacci numbers.
// This approach has an exponential time complexity (O(2^n)) due to redundant calculations,
// making it very inefficient for larger values of 'n'.
// For example, fibonacciRecursive(5) will compute fibonacciRecursive(3) twice,
// fibonacciRecursive(2) three times, and so on.
long long fibonacciRecursive(int k) {
    if (k <= 0) {
        return 0;
    } else if (k == 1) {
        return 1;
    }
    return fibonacciRecursive(k - 1) + fibonacciRecursive(k - 2);
}

int main() {
    int n;
    std::cout << "Enter a positive integer 'n': ";
    std::cin >> n;

    if (n <= 0) {
        // Consistent with problem statement expecting a positive integer,
        // this version also prints nothing for non-positive 'n'.
        // The primary error for this file is efficiency, not input validation.
    } else {
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << fibonacciRecursive(i);
        }
    }
    std::cout << std::endl;

    return 0;
}