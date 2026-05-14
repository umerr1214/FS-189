#include <iostream>
#include <limits> // Required for checking integer limits, though not used for the error itself

// Function to reverse an integer (potential for semantic error: integer overflow)
int reverseNumber(int n) {
    int reversed_n = 0; // Using 'int' which can lead to overflow for large reversed numbers
    while (n != 0) {
        int digit = n % 10;
        // No explicit check for integer overflow is performed before updating reversed_n.
        // If the reversed number exceeds INT_MAX, an overflow will occur.
        reversed_n = reversed_n * 10 + digit;
        n /= 10;
    }
    return reversed_n;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverseNumber(n) << std::endl;
    return 0;
}