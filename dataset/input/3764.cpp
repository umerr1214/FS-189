#include <iostream>

// Function to swap two integers by reference using arithmetic operations
// This method is generally less readable and can lead to integer overflow
// for very large numbers, though it works for typical integer ranges.
void swapNumbers(int& x, int& y) {
    x = x + y; // x now holds the sum
    y = x - y; // y now holds the original x (sum - original y)
    x = x - y; // x now holds the original y (sum - original x)
}

int main() {
    int _a, _b; // Cryptic variable names

    std::cout << "Enter two numbers: "; // Vague prompt
    std::cin >> _a >> _b; // No input validation

    std::cout << "Before swap: _a = " << _a << ", _b = " << _b << std::endl; // Inconsistent spacing

    swapNumbers(_a, _b);

    std::cout << "After swap: _a = " << _a << ", _b = " << _b << std::endl; // Inconsistent spacing

    return 0;
}