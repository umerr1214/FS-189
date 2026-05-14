#include <iostream>
using namespace std;

long long factorial(int n) {
    // Robustness Issue: No check for negative numbers.
    // If n < 0, infinite recursion (stack overflow).
    // e.g. factorial(-1) -> -1 * factorial(-2) ...
    
    // Missing: if (n < 0) return 0; // or error
    
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    // Stack Overflow
    // factorial(-5);
    return 0;
}
