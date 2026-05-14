#include <iostream>

// Function to calculate GCD using Euclidean algorithm (pass by value)
// This implementation assumes positive inputs for correct mathematical behavior of GCD
// and relies on C++'s modulo operator behavior which can be problematic with negative numbers.
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // The program proceeds with calculation without validating if numbers are positive.
    // Entering negative numbers will lead to incorrect GCD results due to modulo behavior.
    // For example, GCD(6, -9) should be 3, but this code might return -3.
    // GCD(-15, 10) should be 5, but this code might return -5.
    int result = findGCD(num1, num2);

    std::cout << "The GCD of " << num1 << " and " << num2 << " is " << result << "." << std::endl;

    return 0;
}