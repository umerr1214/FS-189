#include <iostream>

int sumDigits(int num) {
    int sum; // SEMANTIC ERROR: 'sum' is uninitialized. Its initial value is indeterminate.
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        return 0; // This path correctly returns 0.
    }
    while (num > 0) {
        sum += num % 10; // Adding to an uninitialized variable leads to undefined behavior.
        num /= 10;
    }
    return sum;
}

int main() {
    int input_num;
    std::cout << "Enter an integer: ";
    std::cin >> input_num;
    std::cout << "Sum of digits: " << sumDigits(input_num) << std::endl;
    return 0;
}