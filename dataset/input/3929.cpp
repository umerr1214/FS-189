#include <iostream>
#include <cmath> // For std::abs if used, not strictly necessary for this logic

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    long long sum_of_digits = 0; // Renamed to reflect the logical error
    bool is_negative = false;

    if (num < 0) {
        is_negative = true;
        num = -num; // Make it positive for processing
    } else if (num == 0) {
        std::cout << "Reversed number: 0" << std::endl;
        return 0;
    }

    while (num > 0) {
        int digit = num % 10;
        sum_of_digits = sum_of_digits + digit; // Logical error: summing digits instead of reversing
        num /= 10;
    }

    if (is_negative) {
        sum_of_digits = -sum_of_digits;
    }

    std::cout << "Reversed number: " << sum_of_digits << std::endl; // Outputting sum instead of reversed

    return 0;
}