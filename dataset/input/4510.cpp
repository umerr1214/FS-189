#include <iostream>

int sumDigits(int num) {
    int sum = 0;
    // Handle negative numbers by taking absolute value
    if (num < 0) {
        num = -num;
    }
    // Handle 0 separately as the loop won't run
    if (num == 0) {
        return 0;
    }
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int input_num;
    cout << "Enter an integer: "; // SYNTAX ERROR: Missing std::
    std::cin >> input_num;
    std::cout << "Sum of digits: " << sumDigits(input_num) << std::endl;
    return 0;
}