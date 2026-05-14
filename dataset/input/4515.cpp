#include <iostream>
#include <cmath> // Required for std::abs

// This is the correct, efficient, and readable implementation.
// It uses arithmetic operations (modulo and division) to extract and sum digits.
// It correctly handles negative numbers by taking the absolute value of the input.
int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }

    // Take the absolute value to handle negative inputs correctly.
    // The sum of digits for -123 is 1+2+3 = 6, not -6.
    n = std::abs(n);

    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Get the last digit
        n /= 10;       // Remove the last digit
    }
    return sum;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    int result = sumDigits(num);
    std::cout << "Sum of digits: " << result << std::endl;
    return 0;
}