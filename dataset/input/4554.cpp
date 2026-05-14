#include <iostream>

// Function to calculate factorial iteratively
long long factorial(int n) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        // Returning 1 as a default, or 0, or throwing an error would be alternatives.
        return 1; 
    }
    // Semantic error: 'result' is declared as 'int'. For n >= 13, the intermediate product
    // will overflow the 'int' type before being cast to 'long long' and returned.
    // The correct approach is to declare 'result' as 'long long' from the start.
    int result = 1; 
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return static_cast<long long>(result); // Cast occurs AFTER the overflow has happened
}

int main() {
    int num1 = 5;
    std::cout << "Factorial of " << num1 << " is: " << factorial(num1) << std::endl; // Correct: 120
    int num2 = 0;
    std::cout << "Factorial of " << num2 << " is: " << factorial(num2) << std::endl; // Correct: 1
    int num3 = 12;
    std::cout << "Factorial of " << num3 << " is: " << factorial(num3) << std::endl; // Correct: 479001600 (fits in int)
    int num4 = 13;
    std::cout << "Factorial of " << num4 << " is: " << factorial(num4) << std::endl; // Incorrect: 13! (6,227,020,800) overflows int
    
    return 0;
}