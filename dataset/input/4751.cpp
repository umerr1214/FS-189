#include <iostream>

// Function to print the first 'n' Fibonacci numbers iteratively
void printFibonacci(int n) {
    if (n <= 0) {
        return; // For n <= 0, print nothing
    }

    int a = 0;
    int b = 1;

    for (int i = 0; i < n; ++i) {
        std::cout << a;
        if (i < n - 1) {
            std::cout << " "; // Print space between numbers
        }
        int next = a + b;
        // Logical error: Incorrect update of 'a' and 'b'
        // Correct: a = b; b = next;
        // The current implementation causes 'a' and 'b' to become equal after the first iteration,
        // leading to a sequence of powers of 2 (after the initial 0 and 1).
        a = next;
        b = a; // 'b' is incorrectly assigned the new value of 'a', which is 'next'
    }
    std::cout << "\n"; // Newline after the sequence
}

int main() {
    // Example calls to demonstrate the logical error
    printFibonacci(5);  // Expected: 0 1 1 2 3, Actual: 0 1 2 4 8
    printFibonacci(10); // Expected: 0 1 1 2 3 5 8 13 21 34, Actual: 0 1 2 4 8 16 32 64 128 256
    printFibonacci(1);  // Expected: 0, Actual: 0 (This case works correctly by coincidence)
    printFibonacci(0);  // Expected: "", Actual: "" (This case works correctly)
    return 0;
}