#include <iostream>

// Recursive function to calculate the n-th Fibonacci number
// Contains a logical error in the base case for n=0
int fibonacci(int n) {
    if (n == 0) {
        return 1; // Logical error: F(0) should be 0, not 1
    } else if (n == 1) {
        return 1;
    } else if (n < 0) { // Handle negative input gracefully, though not strictly required by question
        return -1; // Or throw an exception
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n_values[] = {0, 1, 2, 3, 5, 10};
    for (int n : n_values) {
        std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl;
    }
    return 0;
}