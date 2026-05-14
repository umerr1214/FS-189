#include <iostream>

// Function to calculate factorial with a robustness issue: integer overflow for large inputs.
// It uses long long but doesn't check if the result exceeds long long's capacity.
long long calculateFactorial(int num) {
    if (num < 0) {
        return -1; // Factorial is not defined for negative numbers, returning -1 as an error indicator.
    }
    if (num == 0) {
        return 1; // 0! = 1
    }

    long long result = 1;
    for (int i = 1; i <= num; ++i) {
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
    // This input (21) will cause long long overflow, leading to an incorrect positive result.
    // The function does not detect or handle this, which is the robustness issue.
    std::cout << "Factorial of 21: " << calculateFactorial(21) << " (Expected: Incorrect value due to overflow)\n"; 
    
    return 0;
}