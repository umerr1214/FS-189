#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    // Efficiency Issue: Naive recursion is O(2^N).
    // For n=40 or 50, it becomes extremely slow.
    // Iterative or memoization is O(N).
    // This file specifically demonstrates the naive recursion efficiency problem.
    
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Slow for large n
    cout << fibonacci(10) << endl;
    return 0;
}
