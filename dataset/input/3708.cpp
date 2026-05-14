#include <iostream>
#include <cmath> // For sqrt

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 0, 1 are not prime
    if (num <= 3) return true;  // 2, 3 are prime

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int start, end;

    std::cout << "Enter the start of the range: ";
    std::cin >> start;

    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    if (start > end) {
        std::cout << "Invalid range: start cannot be greater than end." << std::endl;
        return 1;
    }

    std::cout << "Prime numbers between " << start << " and " << end << " are:" << std::endl;
    bool found_prime = false;
    int prime_count; // SEMANTIC ERROR: This variable is declared but not initialized.

    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
            found_prime = true;
            prime_count++; // Undefined behavior: incrementing an uninitialized variable.
        }
    }
    if (!found_prime) {
        std::cout << "No prime numbers found in the specified range.";
    }
    std::cout << std::endl;
    std::cout << "Total primes found: " << prime_count << std::endl; // Prints an indeterminate value

    return 0;
}