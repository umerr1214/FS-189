#include <iostream>
#include <string> // Not strictly needed but good practice for C++ programs

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    int sumOfDigits = 0;
    // This program calculates the sum of digits.
    // For negative numbers, it will sum the negative digits (e.g., -123 results in -6).
    // It does not take the absolute value of the number before calculation.
    while (num != 0) {
        int digit = num % 10; // Extracts the last digit (e.g., -123 % 10 is -3)
        sumOfDigits += digit;
        num /= 10; // Removes the last digit (e.g., -123 / 10 is -12)
    }

    std::cout << "Sum of digits: " << sumOfDigits << std::endl;

    return 0;
}