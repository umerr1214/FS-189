#include <iostream>

// This program demonstrates a Readability/Efficiency Issue:
// It uses a naive recursive approach to calculate Fibonacci numbers,
// which has an exponential time complexity (O(2^N)).
// This leads to very poor performance for larger N values and can
// cause stack overflow for extremely large N.
long long fibonacci(int n) {
    if (n <= 0) {
        // While not strictly correct for a 1-indexed Nth term,
        // this is a common base case in some Fibonacci definitions.
        // However, it's not ideal for the problem context.
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    // Inefficient: recalculates fibonacci(n-1) and fibonacci(n-2)
    // and many common subproblems multiple times.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    std::cin >> N;
    long long result = fibonacci(N);
    std::cout << result << std::endl;
    return 0;
}