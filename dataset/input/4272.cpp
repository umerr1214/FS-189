#include <iostream>
#include <limits> // For numeric_limits

// Recursive function to calculate the n-th Fibonacci number
// This implementation is correct for small 'n', but will suffer from
// integer overflow for large 'n' because it uses 'int' as return type.
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // This recursive call will lead to integer overflow for large n (e.g., n >= 47)
        // because the return type 'int' cannot hold the large Fibonacci numbers.
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n_small = 10;
    std::cout << "F(" << n_small << ") = " << fibonacci(n_small) << std::endl; // F(10) = 55 (correct)

    // Test case that will likely cause integer overflow for a 32-bit signed int
    // F(46) = 1,836,311,903
    // F(47) = 2,971,215,073 (exceeds INT_MAX = 2,147,483,647)
    int n_large = 47; 
    std::cout << "F(" << n_large << ") = " << fibonacci(n_large) << std::endl; // Will be incorrect due to overflow

    return 0;
}