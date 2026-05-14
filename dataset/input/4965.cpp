#include <iostream>
#include <cmath> // For std::sqrt

// Function to check if a number is perfect
bool isPerfect(int num) {
    // According to the definition, a perfect number is a positive integer.
    // Numbers less than or equal to 1 cannot be perfect numbers.
    // This handles 0, 1, and negative numbers robustly.
    if (num <= 1) {
        return false;
    }

    // Initialize sum of proper divisors. 1 is always a proper divisor for num > 1.
    long long sumOfDivisors = 1; 

    // Iterate from 2 up to the square root of num.
    // This is the most efficient way to find all divisors.
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sumOfDivisors += i;          // Add divisor 'i'
            if (i * i != num) {          // If 'i' is not the square root, then 'num/i' is a distinct divisor
                sumOfDivisors += (num / i); // Add the corresponding divisor 'num/i'
            }
        }
    }
    // A number is perfect if the sum of its proper positive divisors equals the number itself.
    return sumOfDivisors == num;
}

int main() {
    // Comprehensive test cases
    std::cout << "isPerfect(6): " << (isPerfect(6) ? "true" : "false") << std::endl;      // Expected: true
    std::cout << "isPerfect(28): " << (isPerfect(28) ? "true" : "false") << std::endl;    // Expected: true
    std::cout << "isPerfect(496): " << (isPerfect(496) ? "true" : "false") << std::endl;  // Expected: true
    std::cout << "isPerfect(8128): " << (isPerfect(8128) ? "true" : "false") << std::endl; // Expected: true
    
    std::cout << "isPerfect(1): " << (isPerfect(1) ? "true" : "false") << std::endl;     // Expected: false
    std::cout << "isPerfect(0): " << (isPerfect(0) ? "true" : "false") << std::endl;     // Expected: false
    std::cout << "isPerfect(-5): " << (isPerfect(-5) ? "true" : "false") << std::endl;   // Expected: false
    std::cout << "isPerfect(7): " << (isPerfect(7) ? "true" : "false") << std::endl;     // Expected: false (prime)
    std::cout << "isPerfect(12): " << (isPerfect(12) ? "true" : "false") << std::endl;   // Expected: false
    std::cout << "isPerfect(25): " << (isPerfect(25) ? "true" : "false") << std::endl;   // Expected: false (square)
    std::cout << "isPerfect(30): " << (isPerfect(30) ? "true" : "false") << std::endl;   // Expected: false
    // The fifth perfect number, fits in int. Sum of divisors also fits.
    std::cout << "isPerfect(33550336): " << (isPerfect(33550336) ? "true" : "false") << std::endl; 
    
    return 0;
}