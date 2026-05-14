#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    // Input validation: Ensure n is a positive integer as specified.
    if (n <= 0) {
        std::cerr << "Input must be a positive integer." << '\n';
        return 1; // Indicate an error
    }

    // Use long long for sum to prevent potential overflow for large 'n'
    // (e.g., sum of integers up to 65535 already exceeds int max for 16-bit int,
    // and can exceed 32-bit int max for n around 65536).
    long long sum = 0;
    
    // Clear and standard 'for' loop for summation from 1 to n.
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Use '\n' instead of std::endl for efficiency, as it doesn't force a buffer flush.
    std::cout << "The sum of integers from 1 to " << n << " is: " << sum << '\n';

    return 0;
}