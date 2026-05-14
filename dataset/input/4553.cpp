#include <iostream>

// Function to calculate factorial iteratively
long long factorial(int n) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        // Returning 1 as a default, or 0, or throwing an error would be alternatives.
        return 1; 
    }
    long long result = 1;
    // Logical error: The loop condition `i < n` causes it to calculate (n-1)! instead of n!
    // For n=0 or n=1, it correctly returns 1 because the loop doesn't run.
    // For n > 1, the result will be incorrect.
    for (int i = 1; i < n; ++i) { 
        result *= i;
    }
    return result;
}

int main() {
    int num1 = 5;
    std::cout << "Factorial of " << num1 << " is: " << factorial(num1) << std::endl; // Expected 120, gets 24 (4!)
    int num2 = 0;
    std::cout << "Factorial of " << num2 << " is: " << factorial(num2) << std::endl; // Expected 1, gets 1 (correct)
    int num3 = 1;
    std::cout << "Factorial of " << num3 << " is: " << factorial(num3) << std::endl; // Expected 1, gets 1 (correct)
    int num4 = 3;
    std::cout << "Factorial of " << num4 << " is: " << factorial(num4) << std::endl; // Expected 6, gets 2 (2!)
    
    return 0;
}