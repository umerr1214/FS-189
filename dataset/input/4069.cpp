#include <iostream>
#include <cmath> // Required for std::abs

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    // Robustness Issue: Does not correctly handle negative numbers.
    // It processes the absolute value but forgets to apply the negative sign back.
    // For input -123, it will output 321 instead of -321.

    // Handle 0 explicitly, though the loop would also result in 0.
    if (number == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    int temp_number = number;
    if (temp_number < 0) {
        temp_number = std::abs(temp_number); // Convert to positive for reversal
    }

    int reversed_number = 0;
    while (temp_number > 0) {
        int digit = temp_number % 10;
        reversed_number = reversed_number * 10 + digit;
        temp_number /= 10;
    }

    // Bug: The negative sign is lost if the original number was negative.
    // It just prints the reversed absolute value.
    std::cout << reversed_number << std::endl;

    return 0;
}