#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Robustness Issue: No check for negative numbers.
    // Infinite recursion if n < 0.
    // e.g. f(-1) -> f(-2) + f(-3)...
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Stack Overflow
    // fibonacci(-5);
    return 0;
}
