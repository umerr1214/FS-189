#include <iostream>
#include <cmath> // Required for std::abs

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    long long reversed_num = 0;

    if (num == 0) {
        std::cout << "Reversed number: 0" << std::endl;
        return 0;
    }

    // Semantic error: Misinterprets "reversing digits" for negative numbers
    // by simply taking the absolute value and reversing, ignoring the original sign.
    num = std::abs(num); 

    while (num > 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    // The sign is not re-applied for negative original numbers.
    // E.g., -123 becomes 123, then reversed to 321, instead of -321.

    std::cout << "Reversed number: " << reversed_num << std::endl;

    return 0;
}