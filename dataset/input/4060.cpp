#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number // Syntax Error: Missing semicolon here

    int sum = 0;
    int tempNumber = number;

    if (tempNumber < 0) {
        tempNumber = -tempNumber;
    }

    while (tempNumber > 0) {
        int digit = tempNumber % 10;
        sum += digit;
        tempNumber /= 10;
    }

    std::cout << "Sum of digits: " << sum << std::endl;

    return 0;
}