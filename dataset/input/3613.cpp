#include <iostream>

// Function to check if a number is prime
// Robustness Issue: This function incorrectly returns true for num = 1.
// While it correctly handles 0 and negative numbers by returning false,
// the case of 1 is a common edge case for primality definitions.
bool isPrime(int num) {
    if (num <= 0) {
        return false; // Correctly handles 0 and negative numbers
    }
    if (num == 1) {
        return true; // Robustness issue: 1 is not considered a prime number by convention.
    }
    // Check for divisibility from 2 up to sqrt(num)
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit;
    std::cout << "Enter a limit: ";
    std::cin >> limit;

    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter an integer." << std::endl;
        return 1;
    }

    std::cout << "Prime numbers up to " << limit << ":" << std::endl;
    // The loop starts from 1, which combined with the isPrime(1) returning true,
    // will incorrectly print 1 if the limit is 1 or greater.
    for (int i = 1; i <= limit; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}