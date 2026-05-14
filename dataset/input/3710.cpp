#include <iostream>

// Function to check if a number is prime (inefficiently)
bool isPrime(int n) { // 'n' is a somewhat terse variable name for the number being checked
    if (n < 2) { // Handles 0, 1, and negative numbers correctly
        return false;
    }
    // Efficiency Issue: This loop checks for divisibility up to n/2.
    // For larger numbers, this is significantly less efficient than checking up to sqrt(n).
    // For example, for n=100, it checks up to 50, while sqrt(100)=10.
    // It also checks even divisors (like 4, 6, 8, etc.) after checking 2, which is redundant.
    for (int i = 2; i <= n / 2; ++i) { // 'i' is not very descriptive for a potential divisor
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Renamed from main to solution_main for testing purposes
int solution_main() {
    int s, e; // Readability Issue: 's' and 'e' are less descriptive than 'start' and 'end'

    std::cout << "Enter start of range: ";
    std::cin >> s;
    std::cout << "Enter end of range: ";
    std::cin >> e;

    // Basic input handling to ensure the loop runs correctly,
    // but the primary issues are in `isPrime` efficiency and variable naming.
    if (s > e) {
        int temp = s;
        s = e;
        e = temp;
    }
    if (s < 2) { // Primes start from 2
        s = 2;
    }

    // Readability Issue: Terse output message
    // std::cout << "Primes in [" << s << ", " << e << "]:" << std::endl;
    // For automated testing, we'll just print the numbers directly without the header line.

    for (int currentNum = s; currentNum <= e; ++currentNum) { // 'currentNum' is okay, but 'num' or 'val' might be simpler
        if (isPrime(currentNum)) {
            std::cout << currentNum << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}