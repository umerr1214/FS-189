#include <iostream>
#include <cmath> // For sqrt

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            retun false; // Syntax error: typo 'retun' instead of 'return'
    }
    return true;
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