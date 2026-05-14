#include <iostream>
#include <cmath> // Required for std::sqrt

// Function to check if a number is prime
// Correct Version: This function efficiently and correctly determines if a number is prime.
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) { // All even numbers greater than 2 are not prime
        return false;
    }
    // Check for divisibility only by odd numbers up to the square root of num
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Prime numbers between 1 and 100:" << std::endl;
    for (int i = 1; i <= 100; ++i) {
        if (is_prime(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}