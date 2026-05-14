#include <iostream>

int sumDigits(int num) {
    int sum = 0;
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        return 0;
    }
    while (num >= 10) { // LOGICAL ERROR: Loop condition should be 'num > 0' to include the last digit
        sum += num % 10;
        num /= 10;
    }
    // The last digit is missed because the loop exits when num becomes a single digit (e.g., 1-9)
    // For example, if num was 123, after summing 3 and 2, num becomes 1. Loop exits, 1 is not added.
    // If num was 7, the loop is never entered, returning 0 instead of 7.
    return sum;
}

int main() {
    int input_num;
    std::cout << "Enter an integer: ";
    std::cin >> input_num;
    std::cout << "Sum of digits: " << sumDigits(input_num) << std::endl;
    return 0;
}