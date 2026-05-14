#include <iostream>
#include <vector>
#include <cmath> // For sqrt

// Function to check if a number is prime using an optimized approach
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true; // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0) return false; // Exclude multiples of 2 and 3

    // Check from 5 onwards with a step of 6 (all primes > 3 are of form 6k +/- 1)
    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cout << "Enter a positive integer N: ";
    
    // Robustness Issue: Handles non-integer input by exiting, but doesn't clear the error
    // state of std::cin or re-prompt, which can be problematic in interactive loops.
    if (!(std::cin >> N)) {
        std::cout << "Error: Invalid input. Please enter an integer.\n";
        return 1; // Indicate error
    }

    // Handles non-positive N by exiting with an error message.
    if (N <= 0) {
        std::cout << "Error: N must be a positive integer.\n";
        return 1; // Indicate error
    }

    // Print primes
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}