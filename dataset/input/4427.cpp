#include <iostream>
// #include <cmath> // Not needed for this incorrect logic

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) { // Handles 0, 1, and negative numbers correctly
        return false;
    }
    if (n == 2) { // Handles 2 correctly
        return true;
    }
    if (n % 2 == 0) { // Handles all even numbers greater than 2 correctly
        return false;
    }
    // LOGICAL ERROR: This code incorrectly assumes all odd numbers greater than 2 are prime.
    // It fails to check for odd divisors for composite numbers like 9, 15, 21 etc.
    return true; // Incorrectly returns true for odd composite numbers
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
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