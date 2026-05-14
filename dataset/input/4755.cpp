#include <iostream>

// Correct Version: Implements the Fibonacci sequence iteratively with good readability and efficiency.
void printFibonacci(int n) {
    if (n <= 0) {
        return; // Prints nothing for non-positive n, as expected.
    }
    if (n == 1) {
        std::cout << 0 << '\n'; // Prints only the first Fibonacci number (0)
        return;
    }

    long long a = 0; // Use long long to prevent integer overflow for large Fibonacci numbers
    long long b = 1; // Use long long to prevent integer overflow for large Fibonacci numbers

    std::cout << a << " " << b; // Print the first two numbers (0 and 1)

    // Iterate from the third number up to n
    for (int i = 2; i < n; ++i) {
        long long nextNum = a + b; // Calculate the next Fibonacci number
        std::cout << " " << nextNum; // Print it, preceded by a space
        a = b; // Update 'a' to the previous 'b'
        b = nextNum; // Update 'b' to the newly calculated number
    }
    std::cout << '\n'; // Use '\n' for efficient newline output (no buffer flush)
}

int main() {
    // Driver code for testing
    // The actual test cases are in the JSON file.
    // This main function is just to make the CPP file a complete program.
    printFibonacci(5); // Example call
    return 0;
}