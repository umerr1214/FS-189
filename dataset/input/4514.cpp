#include <iostream>
#include <string>
#include <numeric> // For std::accumulate
#include <cmath>   // For std::abs

// This version converts the integer to a string, then iterates over the string
// to sum the digits. This is generally less efficient than arithmetic operations
// for integer digit summation and adds overhead of string conversion and char-to-int conversion.
// It also uses a less conventional approach with std::accumulate which might be less
// immediately readable for this simple task compared to a direct loop.
int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    std::string s = std::to_string(std::abs(n)); // Convert to string after taking absolute value
    int sum = 0;
    for (char c : s) {
        sum += c - '0'; // Convert char digit to int
    }
    return sum;
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    int result = sumDigits(num);
    std::cout << "Sum of digits: " << result << std::endl;
    return 0;
}