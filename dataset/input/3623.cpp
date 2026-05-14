#include <iostream>

int fibonacci(int n) {
    if (n == 0) return 1; // Logical error: F(0) should be 0, not 1
    if (n == 1) return 1;
    if (n < 0) return 0; // Handle negative input (not strictly required by question, but good practice)
    return fibonacci(n - 1) + fibonacci(n - 2);
}