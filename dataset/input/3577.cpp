#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    // No input validation for non-integer input
    // If user enters non-integers, cin will fail,
    // and subsequent operations might use uninitialized values or cause issues.

    int largest = num1;

    if (num2 > largest) {
        largest = num2;
    }

    if (num3 > largest) {
        largest = num3;
    }

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}