#include <iostream>

// Function to calculate GCD using Euclidean algorithm
int calculateGCD(int a, int b) {
    // Ensure inputs are non-negative for standard Euclidean algorithm behavior
    // For simplicity of demonstrating syntax error, we assume positive inputs or
    // let the default behavior of % handle negative numbers for now.
    // The core algorithm logic is correct.
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1 = 48;
    int num2 = 18;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl // Syntax Error: Missing semicolon
    
    num1 = 101;
    num2 = 103;
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << std::endl;
    
    return 0;
}