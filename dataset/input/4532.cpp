#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int input_limit_N; // Verbose variable name
    std::cout << "Enter a positive integer N: ";
    std::cin >> input_limit_N; // No explicit check for non-integer input or N <= 0

    if (input_limit_N <= 1) { // Handles N=0, N=1, negative numbers by printing nothing
        // No explicit error message for non-positive N, just no primes printed.
        std::cout << "\n";
        return 0;
    }

    // Inefficient primality test: Checks divisibility up to candidate_number-1
    // This leads to O(N^2) complexity for finding primes up to N.
    for (int candidate_number = 2; candidate_number <= input_limit_N; ++candidate_number) {
        bool is_this_number_a_prime = true; // Long flag name, no comments
        for (int current_divisor = 2; current_divisor < candidate_number; ++current_divisor) { 
            if (candidate_number % current_divisor == 0) {
                is_this_number_a_prime = false;
                break;
            }
        }
        if (is_this_number_a_prime) {
            std::cout << candidate_number << " ";
        }
    }
    std::cout << "\n";

    return 0;
}