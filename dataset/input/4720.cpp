#include <iostream>
#include <cmath> // For sqrt (though not strictly needed in this version)

// Function definition with a syntax error: missing closing brace
bool isPrime(int n) {
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
// Missing '}' here for the function isPrime. This will cause a compilation error.

int main() {
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    std::cout << "Is 7 prime? " << isPrime(7) << std::endl;      // Expected: true
    std::cout << "Is 4 prime? " << isPrime(4) << std::endl;      // Expected: false
    std::cout << "Is 2 prime? " << isPrime(2) << std::endl;      // Expected: true
    std::cout << "Is 1 prime? " << isPrime(1) << std::endl;      // Expected: false
    std::cout << "Is 0 prime? " << isPrime(0) << std::endl;      // Expected: false
    std::cout << "Is 11 prime? " << isPrime(11) << std::endl;    // Expected: true
    return 0;
}