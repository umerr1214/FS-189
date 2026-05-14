#include <iostream>
#include <string> // Required for string operations if needed, but not directly used in this simple version

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) { // Correctly handles 0, 1, and negative numbers as not prime
        return false;
    }
    // Check for divisibility from 2 up to the square root of num
    // Using i * i <= num avoids floating point operations with sqrt()
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; // Found a divisor, so it's not prime
        }
    }
    return true; // No divisors found, so it's prime
}

// Renamed from main to solution_main for testing purposes
int solution_main() {
    int start, end;

    std::cout << "Enter the start of the range: ";
    std::cin >> start;
    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    // Robustness Issue:
    // The code does not explicitly handle cases where 'start' is greater than 'end'.
    // In such a scenario, the loop 'for (int i = start; i <= end; ++i)' will not execute,
    // resulting in no output without any error message or correction (like swapping the values).
    // This can be confusing for a user expecting a range scan regardless of input order.
    // Also, negative inputs for start/end are handled by isPrime returning false,
    // but the program doesn't provide specific feedback or adjust the range to start from 2.

    // std::cout << "Prime numbers in the range [" << start << ", " << end << "]:" << std::endl;
    // For automated testing, we'll just print the numbers directly without the header line.
    
    bool foundAny = false;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
            foundAny = true;
        }
    }
    // A newline is often expected after output.
    // If nothing is found, an empty line is printed.
    std::cout << std::endl; 

    return 0;
}