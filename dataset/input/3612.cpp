#include <iostream>
#include <cmath> // For sqrt
#include <limits> // For std::numeric_limits

// Function to check if a number is prime
bool isPrime(int num) { // Semantic Error: num is int, but main passes long long.
                         // If the long long limit exceeds INT_MAX, it will be truncated.
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    long long limit; // Reads a long long limit
    std::cout << "Enter a limit: ";
    std::cin >> limit;
    std::cout << "Prime numbers up to " << limit << ":\n";
    for (long long i = 0; i <= limit; ++i) { // Iterates up to long long limit
        // Semantic Error occurs here: implicit conversion from long long to int.
        // If i > INT_MAX, i will be truncated when passed to isPrime,
        // potentially leading to incorrect results or missed primes for large numbers.
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}