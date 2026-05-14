#include <iostream>
#include <cmath>    // For std::abs
#include <limits>   // For std::numeric_limits

bool isPrime(int n) {
    // Semantic Error: The function uses std::abs(n) to handle potential negative inputs.
    // If 'n' is std::numeric_limits<int>::min() (typically -2,147,483,648),
    // calling std::abs on it results in undefined behavior due to integer overflow,
    // as its positive counterpart cannot be represented in a signed int.
    n = std::abs(n);

    if (n <= 1) {
        return false;
    }
    // Loop checks for divisors from 2 up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    std::cout << "Is 7 prime? " << isPrime(7) << std::endl;      // Expected: true
    std::cout << "Is 4 prime? " << isPrime(4) << std::endl;      // Expected: false
    std::cout << "Is 2 prime? " << isPrime(2) << std::endl;      // Expected: true
    std::cout << "Is 1 prime? " << isPrime(1) << std::endl;      // Expected: false
    std::cout << "Is 0 prime? " << isPrime(0) << std::endl;      // Expected: false
    std::cout << "Is -5 prime? " << isPrime(-5) << std::endl;    // Expected: true (abs(-5)=5)
    std::cout << "Is -4 prime? " << isPrime(-4) << std::endl;    // Expected: false (abs(-4)=4)
    // The following line is commented out in the driver to avoid actual undefined behavior
    // during standard execution, but it represents a valid input that triggers the semantic error.
    // std::cout << "Is INT_MIN prime? " << isPrime(std::numeric_limits<int>::min()) << std::endl;
    return 0;
}