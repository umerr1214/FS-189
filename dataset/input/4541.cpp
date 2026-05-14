#include <iostream>

// Function to calculate GCD using Euclidean algorithm (recursive variant)
int calculateGCD(int a, int b) {
    // Logical Error: Incorrect base case
    if (b == 0) {
        return b; // Should return 'a' when b is 0, as GCD(a, 0) = a
    }
    return calculateGCD(b, a % b);
}

int main() {
    int num1 = 48;
    int num2 = 18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 6, Actual: 0
    
    num1 = 101;
    num2 = 103;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 1, Actual: 0
    
    num1 = 7;
    num2 = 0;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl; // Expected: 7, Actual: 0

    return 0;
}