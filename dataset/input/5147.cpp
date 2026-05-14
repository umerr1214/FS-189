#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 1; // Logical error: F(0) should be 0, not 1
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer N: ";
    std::cin >> n;
    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}