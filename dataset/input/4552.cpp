#include <iostream>

// Function to calculate factorial iteratively
long long factorial(int n) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        // For this problem, we assume non-negative input as per question.
        // Returning 1 for negative n is also a common choice if not an error.
        return 1; 
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num1 = 5;
    std::cout << "Factorial of " << num1 << " is: " << factorial(num1) << std::endl
    int num2 = 0;
    std::cout << "Factorial of " << num2 << " is: " << factorial(num2) << std::endl;
    int num3 = 10;
    std::cout << "Factorial of " << num3 << " is: " << factorial(num3) << std::endl;
    
    return 0;
}