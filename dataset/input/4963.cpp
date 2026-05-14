#include <iostream>

// Function to check if a number is perfect
bool isPerfect(int n) {
    // This function has a robustness issue:
    // It incorrectly returns true for n=0.
    // A perfect number is defined as a *positive* integer.
    // For n=0, the loop for (int i = 1; i <= n / 2; ++i) does not execute,
    // sum_divisors remains 0. Then, sum_divisors == n (0 == 0) evaluates to true.
    // It also does not explicitly handle negative numbers, though the loop condition
    // implicitly makes them return false, which is correct.
    
    int sum_divisors = 0;
    for (int i = 1; i <= n / 2; ++i) { 
        if (n % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == n;
}

int main() {
    // Test cases
    std::cout << "isPerfect(6): " << (isPerfect(6) ? "true" : "false") << std::endl;      // Expected: true
    std::cout << "isPerfect(28): " << (isPerfect(28) ? "true" : "false") << std::endl;    // Expected: true
    std::cout << "isPerfect(12): " << (isPerfect(12) ? "true" : "false") << std::endl;   // Expected: false
    std::cout << "isPerfect(1): " << (isPerfect(1) ? "true" : "false") << std::endl;     // Expected: false
    std::cout << "isPerfect(0): " << (isPerfect(0) ? "true" : "false") << std::endl;     // Expected: false (Robustness Issue: returns true)
    std::cout << "isPerfect(-6): " << (isPerfect(-6) ? "true" : "false") << std::endl;   // Expected: false
    std::cout << "isPerfect(496): " << (isPerfect(496) ? "true" : "false") << std::endl; // Expected: true

    return 0;
}