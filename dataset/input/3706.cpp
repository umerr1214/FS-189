#include <iostream>
#include <cmath> // For sqrt

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 0, 1 are not prime
    if (num <= 3) return true;  // 2, 3 are prime

    // This is a basic optimization:
    // Any prime greater than 3 can be written in the form 6k +/- 1.
    // Also, all even numbers > 2 are not prime.
    // All multiples of 3 > 3 are not prime.
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Check for factors from 5 onwards
    // We only need to check up to sqrt(num)
    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int start, end;

    std::cout << "Enter the start of the range: ";
    std::cin >> start;

    std::cout << "Enter the end of the range: " // SYNTAX ERROR: Missing semicolon here
    std::cin >> end;

    if (start > end) {
        std::cout << "Invalid range: start cannot be greater than end." << std::endl;
        return 1;
    }

    std::cout << "Prime numbers between " << start << " and " << end << " are:" << std::endl;
    bool found_prime = false;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
            found_prime = true;
        }
    }
    if (!found_prime) {
        std::cout << "No prime numbers found in the specified range.";
    }
    std::cout << std::endl;

    return 0;
}