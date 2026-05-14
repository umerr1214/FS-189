#include <iostream>
#include <limits> // For potential future overflow checks, though not strictly needed for this problem's scope

long long factorial(int n) {
    if (n < 0) {
        // According to the problem statement "non-negative integer n",
        // negative input is invalid. Return -1 to signal an error.
        return -1;
    }
    if (n == 0) {
        return 1; // Base case: 0! = 1
    }

    long long result = 1;
    // Iterate from 1 up to n to calculate factorial
    for (int i = 1; i <= n; ++i) {
        // A truly robust solution might check for overflow here:
        // if (result > std::numeric_limits<long long>::max() / i) {
        //     return -2; // Indicate overflow
        // }
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;
    std::cout << "Factorial of 0: " << factorial(0) << std::endl;
    std::cout << "Factorial of 1: " << factorial(1) << std::endl;
    std::cout << "Factorial of 10: " << factorial(10) << std::endl;
    std::cout << "Factorial of 20: " << factorial(20) << std::endl;
    std::cout << "Factorial of -3 (error case): " << factorial(-3) << std::endl; // Should return -1
    return 0;
}