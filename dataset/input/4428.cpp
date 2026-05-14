#include <iostream>
#include <cmath> // For std::sqrt
#include <limits> // For std::numeric_limits

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    // Check for divisibility by odd numbers up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned int num_unsigned; // SEMANTIC ERROR: Reading user input into an unsigned int.
                               // The question asks for a "positive integer" (typically implying a signed int
                               // where negative values are explicitly handled).
                               // If a large positive number (e.g., > INT_MAX) is entered, it will be stored
                               // correctly in num_unsigned, but then its implicit conversion to 'int' below
                               // will cause an integer overflow, leading to a negative value.
    std::cout << "Enter a positive integer: ";
    std::cin >> num_unsigned;

    // Check if input stream failed (e.g., non-numeric input, or negative number for unsigned int)
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        return 1;
    }

    // Implicit conversion from unsigned int to int.
    // This is the semantic error's point of failure for large positive inputs.
    // If num_unsigned > INT_MAX, 'num' will become a negative value due to integer overflow.
    int num = num_unsigned;

    if (num <= 0) { // This check now applies to the potentially overflowed/converted 'num'
        std::cout << "Please enter a positive integer." << std::endl;
    } else {
        if (isPrime(num)) {
            std::cout << num << " is a prime number." << std::endl;
        } else {
            std::cout << num << " is not a prime number." << std::endl;
        }
    }
    return 0;
}