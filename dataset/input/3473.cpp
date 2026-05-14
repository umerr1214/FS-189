#include <iostream>

// Function containing the core logic to calculate sum of digits
int getSumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }

    int sum = 0;
    while (num > 0) {
        // Logical Error: Adding the entire remaining number instead of just the last digit
        sum = sum + num; // INCORRECT: should be sum = sum + (num % 10);
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

    std::cout << "Sum of digits for " << num << " is: " << sum << std::endl;

    return 0;
}