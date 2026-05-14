#include <iostream> // Required for input/output operations
#include <cmath>    // Required for std::sqrt

/**
 * @brief Checks if a given integer is a prime number.
 *
 * A prime number is a natural number greater than 1 that has no positive divisors
 * other than 1 and itself. This implementation includes optimizations for efficiency.
 *
 * @param num The integer to check for primality.
 * @return true if num is prime, false otherwise.
 */
bool isPrime(int num) {
    // Prime numbers are natural numbers greater than 1.
    // 0, 1, and negative numbers are not prime.
    if (num <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (num == 2) {
        return true;
    }
    // All other even numbers are not prime, so we can skip them.
    if (num % 2 == 0) {
        return false;
    }
    // Check for divisibility from 3 up to the square root of num,
    // incrementing by 2 to only check odd divisors.
    // Using `i * i <= num` is an alternative to `i <= std::sqrt(num)`
    // to avoid floating-point calculations, but `std::sqrt` is clear.
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit; // Variable to store the user-specified upper limit

    std::cout << "Enter a positive integer limit to find primes up to: ";
    std::cin >> limit; // Read the limit from user input

    // Input validation: Check if input was successful
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
        return 1; // Indicate an error
    }

    // Handle limits where no primes exist (less than 2)
    if (limit < 2) {
        std::cout << "There are no prime numbers to display up to " << limit << "." << std::endl;
        return 0; // Exit gracefully
    }

    std::cout << "Prime numbers up to " << limit << ":" << std::endl;
    // Iterate from 2 up to the limit and print prime numbers
    for (int currentNum = 2; currentNum <= limit; ++currentNum) {
        if (isPrime(currentNum)) {
            std::cout << currentNum << " ";
        }
    }
    std::cout << std::endl; // Newline at the end for clean output

    return 0; // Indicate successful execution
}