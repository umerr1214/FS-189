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
        }
    }
    return true // SYNTAX ERROR: Missing semicolon here
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