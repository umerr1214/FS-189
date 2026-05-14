#include <iostream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
// Logical Error: Incorrectly returns true if the number is divisible by any i,
// instead of returning false. This marks many composite numbers as prime.
bool isPrime(int num) {
    if (num <= 1) return false;
    // Special case for 2, as the loop starts from i=2
    if (num == 2) return true;
    if (num % 2 == 0) return false; // Optimization for even numbers > 2

    for (int i = 3; i * i <= num; i += 2) { // Only check odd divisors
        if (num % i == 0) {
            return true; // LOGICAL ERROR: Should be 'return false;'
        }
    }
    return true; // If no divisors found (or incorrectly returned true), it's prime
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
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}