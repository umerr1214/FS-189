#include <iostream>

// Recursive function to calculate the n-th Fibonacci number
// Using 'int' return type which can lead to overflow for larger n
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
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

    // The 'result' variable is also 'int', susceptible to overflow
    int result = fibonacci(n);
    std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;
    return 0;
}