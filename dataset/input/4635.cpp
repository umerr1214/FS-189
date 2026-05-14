#include <iostream>
#include <limits> // Required for numeric_limits

// Correct and robust function to calculate factorial.
// Handles 0!, negative numbers, and potential long long overflow for very large inputs.
long long calculateFactorial(int num) {
    if (num < 0) {
        return -1; // Factorial is not defined for negative numbers.
    }
    if (num == 0) {
        return 1; // 0! = 1
    }
    
    // Factorials grow very quickly. 20! is the largest that fits into a signed long long.
    // For num > 20, the result will overflow long long.
    if (num > 20) { 
        return -2; // Indicate an overflow condition for inputs too large for long long.
                   // Using -2 to distinguish from "not defined for negative".
    }

    long long result = 1;
    for (int i = 1; i <= num; ++i) {
        // Optional: Check for intermediate overflow before multiplication.
        // For factorial, result * i can exceed LLONG_MAX.
        // This check is more robust for general multiplication, but for factorial,
        // we already know that num > 20 will overflow, so the initial check is sufficient.
        // If (std::numeric_limits<long long>::max() / i < result) {
        //     return -2; // Overflow would occur
        // }
        result *= i;
    }
    return result;
}

int main() {
    // Test cases
    std::cout << "Factorial of 0: " << calculateFactorial(0) << " (Expected: 1)\n";
    std::cout << "Factorial of 5: " << calculateFactorial(5) << " (Expected: 120)\n";
    std::cout << "Factorial of -3: " << calculateFactorial(-3) << " (Expected: -1)\n";
    std::cout << "Factorial of 12: " << calculateFactorial(12) << " (Expected: 479001600)\n";
    std::cout << "Factorial of 20: " << calculateFactorial(20) << " (Expected: 2432902008176640000)\n";
    // Test case for overflow handling
    std::cout << "Factorial of 21: " << calculateFactorial(21) << " (Expected: -2 for overflow)\n"; 
    std::cout << "Factorial of 25: " << calculateFactorial(25) << " (Expected: -2 for overflow)\n"; 
    
    return 0;
}