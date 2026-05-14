#include <iostream>
#include <cmath> // For std::sqrt

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
    int num;
    std::cout << "Enter a positive integer: " // SYNTAX ERROR: Missing semicolon here
    std::cin >> num;

    if (num <= 0) {
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