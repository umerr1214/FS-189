#include <iostream>

// Function to print the first 'n' Fibonacci numbers iteratively
void printFibonacci(int n) {
    if (n <= 0) {
        return; // For n <= 0, print nothing
    }

    int a = 0;
    int b = 1; // Missing semicolon here, causing a syntax error

    for (int i = 0; i < n; ++i) {
        std::cout << a;
        if (i < n - 1) {
            std::cout << " "; // Print space between numbers
        }
        int next = a + b;
        a = b;
        b = next;
    }
    std::cout << "\n"; // Newline after the sequence
}

int main() {
    // Example calls (this part of the code is not meant to run successfully due to the error)
    // printFibonacci(5);
    // printFibonacci(1);
    // printFibonacci(0);
    return 0;
}