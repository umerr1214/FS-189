#include <iostream>
#include <cmath> // For sqrt

// Function to check if a number is prime
bool isPrime(int num) {
    // Logical Error: Does not correctly handle num = 0 or num = 1.
    // For num = 0 or num = 1, the loop condition (i*i <= num) will be false
    // immediately, and the function will incorrectly return true.
    // A correct implementation would include: 'if (num < 2) return false;'.

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true; // This will be reached for 0 and 1, incorrectly identifying them as prime.
}

int main() {
    int limit;
    std::cout << "Enter a limit: ";
    std::cin >> limit;
    std::cout << "Prime numbers up to " << limit << ":\n";
    for (int i = 0; i <= limit; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}