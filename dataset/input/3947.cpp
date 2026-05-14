#include <iostream>
#include <cmath> // For std::sqrt

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    // Check for divisibility from 2 up to the square root of n
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false; // Found a divisor, so it's not prime
        } else {
            // LOGICAL ERROR: This line incorrectly returns true if n is not divisible by the current 'i',
            // without checking other potential divisors. For example, for n=9, it checks 9%2, finds it's not 0,
            // and immediately returns true, incorrectly marking 9 as prime.
            return true;
        }
    }
    // This line should be reached if no divisors were found throughout the loop.
    // Due to the error above, it might not be reached for some primes or composites.
    return true;
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }

    return 0;
}