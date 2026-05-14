#include <iostream>

// Robustness Issue: Uses 'int' for Fibonacci numbers, leading to overflow for large 'n'.
void printFibonacci(int n) {
    if (n <= 0) {
        return; // Prints nothing for non-positive n, which is acceptable behavior.
    }
    if (n == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int a = 0; // Using int, will overflow for F(47) and beyond
    int b = 1; // Using int, will overflow for F(47) and beyond

    std::cout << a << " " << b;

    for (int i = 2; i < n; ++i) {
        int nextNum = a + b; // Potential overflow here
        std::cout << " " << nextNum;
        a = b;
        b = nextNum;
    }
    std::cout << '\n';
}

int main() {
    // Driver code for testing
    // The actual test cases are in the JSON file.
    // This main function is just to make the CPP file a complete program.
    printFibonacci(5); // Example call
    return 0;
}