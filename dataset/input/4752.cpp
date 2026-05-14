#include <iostream>

// Function to print the first 'n' Fibonacci numbers iteratively
void printFibonacci(int n) {
    if (n <= 0) {
        // Semantic error: For n=0, the problem implies printing no numbers (empty output).
        // This code semantically misinterprets 'n=0' by printing '0\n',
        // suggesting that '0' is always the first number to be printed, even when 'n' is zero.
        std::cout << "0\n";
        return;
    }

    int a = 0;
    int b = 1;

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
    // Example calls to demonstrate the semantic error for n=0
    printFibonacci(0); // Expected: "", Actual: "0\n"
    printFibonacci(1); // Expected: "0\n", Actual: "0\n" (Correct)
    printFibonacci(5); // Expected: "0 1 1 2 3\n", Actual: "0 1 1 2 3\n" (Correct)
    return 0;
}