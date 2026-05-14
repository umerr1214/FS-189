#include <iostream>

// Recursive function to calculate the n-th Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 10;
    std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl // Missing semicolon here
    
    n = 5;
    std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}