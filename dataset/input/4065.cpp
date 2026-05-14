#include <iostream>
#include <cmath> // Required for std::abs

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int sumOfDigits = 0;
    // Work with the absolute value of the number to correctly sum digits for negative inputs.
    // E.g., for -123, sum of digits is 1+2+3 = 6.
    int tempNumber = std::abs(number);

    // Handle the special case where the input is 0 directly.
    // The while loop condition 'tempNumber > 0' would not execute for 0,
    // so sumOfDigits would remain 0, which is correct.
    // However, explicitly handling it or setting tempNumber for 0 ensures clarity.
    if (number == 0) { // Using original 'number' to avoid changing tempNumber if it was 0
        sumOfDigits = 0;
    } else {
        while (tempNumber > 0) {
            int digit = tempNumber % 10; // Get the last digit
            sumOfDigits += digit;        // Add to sum
            tempNumber /= 10;            // Remove the last digit
        }
    }

    std::cout << "The sum of the digits is: " << sumOfDigits << std::endl;

    return 0;
}