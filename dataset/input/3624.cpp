#include <iostream>

int fibonacci(int n) {
    // Semantic error: Missing base cases for n=0 and n=1.
    // This will lead to infinite recursion for any non-negative n,
    // eventually causing a stack overflow.
    return fibonacci(n - 1) + fibonacci(n - 2);
}