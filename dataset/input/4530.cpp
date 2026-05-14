#include <iostream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
// Semantic Error: Incorrectly treats the number 1 as a prime number.
// The definition of a prime number states it must be greater than 1.
bool isPrime(int num) {
    if (num <= 0) return false; // Numbers less than or equal to 0 are not prime
    if (num == 1) return true; // SEMANTIC ERROR: 1 is not a prime number by definition
    if (num == 2) return true; // 2 is prime
    if (num % 2 == 0) return false; // All other even numbers are not prime

    // Check for odd divisors from 3 up to sqrt(num)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    if (N < 1) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

    std::cout << "Prime numbers up to " << N << ":" << std::endl;
    for (int i = 1; i <= N; ++i) { // Loop starts from 1 to check isPrime(1)
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}