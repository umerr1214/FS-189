#include <iostream>

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;

    int sum = 0;
    // Robustness Issue:
    // The program does not validate if the input is positive.
    // If a non-positive integer (0 or negative) is entered,
    // the 'while (number > 0)' loop will not execute,
    // resulting in 'sum' remaining 0.
    // This is incorrect behavior for negative numbers (e.g., -123 should ideally be 6 if absolute value is considered)
    // and misleading for 0 as the question specifies a "positive integer".
    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }

    std::cout << "The sum of the digits is: " << sum << std::endl;

    return 0;
}