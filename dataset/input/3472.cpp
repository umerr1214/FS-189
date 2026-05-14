#include <iostream>

// Function containing the core logic to calculate sum of digits
int getSumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }

    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
    return sum;
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    int sum = getSumOfDigits(num);

    std::cout << "Sum of digits for " << num << " is: " << sum std::endl; // SYNTAX ERROR: missing semicolon

    return 0;
}