#include <iostream>
#include <vector>
#include <cmath> // For sqrt function

// Helper function to check if a number is prime efficiently
// Uses optimizations like checking divisibility only up to sqrt(num)
// and skipping multiples of 2 and 3.
bool isPrime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
    if (num <= 3) return true;  // 2 and 3 are prime numbers

    // If num is divisible by 2 or 3, it's not prime
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Check for primality using a step of 6
    // All primes greater than 3 can be written in the form 6k +/- 1
    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cout << "Enter a positive integer N: ";
    
    // Input validation: Check if input is a valid integer
    if (!(std::cin >> N)) {
        std::cout << "Error: Invalid input. Please enter an integer.\n";
        return 1; // Exit with an error code
    }

    // Input validation: N must be a positive integer as per the question
    if (N <= 0) {
        std::cout << "Error: N must be a positive integer.\n";
        return 1; // Exit with an error code
    }

    // Iterate from 2 up to N and print prime numbers
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n"; // Print a newline at the end of the output

    return 0;
}