#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int sum = 0;
    int tempNumber = number;

    if (tempNumber < 0) {
        tempNumber = -tempNumber;
    }

    while (tempNumber > 0) {
        int digit = tempNumber % 10;
        sum = digit; // Logical Error: Should be sum += digit; This only stores the last digit.
        tempNumber /= 10;
    }

    std::cout << "Sum of digits: " << sum << std::endl;

    return 0;
}