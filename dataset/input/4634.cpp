#include <iostream>

// Function to calculate factorial using recursion.
// This approach is generally less efficient than an iterative solution for factorial
// due to function call overhead and potential stack depth issues for very large 'num'.
long long calculateFactorial(int num) {
    if (num < 0) {
        return -1; // Factorial is not defined for negative numbers, returning -1.
    }
    if (num == 0) {
        return 1; // Base case: 0! = 1
    }
    // Recursive step: n! = n * (n-1)!
    return num * calculateFactorial(num - 1);
}

int main() {
    // Test cases
    std::cout << "Factorial of 0: " << calculateFactorial(0) << " (Expected: 1)\n";
    std::cout << "Factorial of 5: " << calculateFactorial(5) << " (Expected: 120)\n";
    std::cout << "Factorial of -3: " << calculateFactorial(-3) << " (Expected: -1)\n";
    std::cout << "Factorial of 10: " << calculateFactorial(10) << " (Expected: 3628800)\n";
    std::cout << "Factorial of 15: " << calculateFactorial(15) << " (Expected: 1307674368000)\n";
    
    return 0;
}