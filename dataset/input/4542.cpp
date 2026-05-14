#include <iostream>
// #include <cmath> // Would be needed for std::abs if we were to fix the semantic issue

// Function to calculate GCD using Euclidean algorithm
int calculateGCD(int a, int b) {
    // Semantic Error: Does not explicitly handle negative inputs by taking absolute values.
    // The mathematical GCD is typically defined as a positive integer.
    // C++'s '%' operator behavior with negative numbers means the result of a % b can be negative.
    // This leads to the function returning negative values for GCD in certain cases,
    // which semantically deviates from the standard definition of GCD.
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Can return a negative value if inputs cause 'a' to be negative at the end.
}

int main() {
    int num1 = 48;
    int num2 = 18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 6, Actual: 6
    
    num1 = -48;
    num2 = 18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 6, Actual: -6 (Semantic issue)
    
    num1 = 48;
    num2 = -18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 6, Actual: 6
    
    num1 = -48;
    num2 = -18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 6, Actual: -6 (Semantic issue)

    num1 = 0;
    num2 = 0;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 0, Actual: 0 (Common convention)

    return 0;
}