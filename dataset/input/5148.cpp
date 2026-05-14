#include <iostream>

int fibonacci(int n) {
    // This implementation is mathematically correct for non-negative n.
    // However, the 'int' return type is insufficient for large N,
    // leading to integer overflow (a semantic error).
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer N: ";
    std::cin >> n;
    // For N=47 or higher, fibonacci(N) will return an incorrect value due to int overflow.
    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}