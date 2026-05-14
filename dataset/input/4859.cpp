#include <iostream>

// Recursive function to calculate the n-th Fibonacci number
int fibonacci(int n) {
    // Incorrect base case: should return 0 for n=0 and 1 for n=1
    if (n <= 1) {
        return 1; // This makes fibonacci(0) = 1 (should be 0)
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Please enter a non-negative integer." << std::endl;
        return 1;
    }

    int result = fibonacci(n);
    std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;
    return 0;
}