#include <iostream>

// Function to reverse an integer (logically incorrect - sums digits)
int reverseNumber(int n) {
    int sum_of_digits = 0; // Incorrect variable name and purpose
    while (n != 0) {
        int digit = n % 10;
        sum_of_digits += digit; // Incorrect operation: should be for reversing, not summing
        n /= 10;
    }
    return sum_of_digits; // Returns sum of digits instead of reversed number
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverseNumber(n) << std::endl;
    return 0;
}