#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int sum = 0;
    // Semantic Error: Using unsigned int for tempNumber without handling potential negative input.
    // If 'number' is negative, 'tempNumber' will undergo implicit conversion to a very large positive unsigned integer,
    // leading to an incorrect sum or an extremely long loop.
    unsigned int tempNumber = number; 

    // No explicit handling for negative numbers here, relying on unsigned conversion.

    while (tempNumber > 0) {
        int digit = tempNumber % 10;
        sum += digit;
        tempNumber /= 10;
    }

    std::cout << "Sum of digits: " << sum << std::endl;

    return 0;
}