#include <iostream>
#include <string> // Not strictly needed for this version, but often included
#include <cmath>  // For std::abs, but this version intentionally omits it for robustness issue

int sumDigits(int n) {
    int sum = 0;
    // This version does not handle negative numbers by taking absolute value
    // For example, if n is -123, it will compute -3 + -2 + -1 = -6
    // instead of 1 + 2 + 3 = 6.
    if (n == 0) {
        return 0;
    }

    // Handles positive numbers correctly, but negative numbers result in a negative sum.
    // For example, -123 will result in -6, while the expected sum of digits is 6.
    while (n != 0) {
        sum += n % 10;
        n /= 10;
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