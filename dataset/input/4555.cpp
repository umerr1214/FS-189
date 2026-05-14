#include <iostream>

long long factorial(int n) {
    if (n < 0) {
        // Robustness issue: Returns 1 for negative numbers instead of indicating an error
        // or handling it appropriately as per "non-negative integer n".
        return 1;
    }
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        // Robustness issue: Does not check for overflow.
        // For n > 20, the result will overflow long long without warning.
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;      // Expected: 120
    std::cout << "Factorial of 0: " << factorial(0) << std::endl;      // Expected: 1
    std::cout << "Factorial of -3: " << factorial(-3) << std::endl;    // Expected (Robust): Error/Invalid, Actual (this code): 1
    std::cout << "Factorial of 20: " << factorial(20) << std::endl;    // Expected: 2432902008176640000
    std::cout << "Factorial of 21: " << factorial(21) << std::endl;    // Expected (Robust): Overflow/Error, Actual (this code): Overflowed value
    return 0;
}