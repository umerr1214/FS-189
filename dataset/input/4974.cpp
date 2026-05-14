#include <iostream>
#include <cmath> // For std::abs

// Function definition
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    n = std::abs(n); // Handle negative numbers
    while (n > 0) {
        // SEMANTIC ERROR: Missing n /= 10; causes an infinite loop for any non-zero 'n'
        count++;
    }
    return count;
}

int main() {
    std::cout << "Digits in 12345: " << countDigits(12345) << std::endl; // This call will cause an infinite loop
    // The program will not reach the following lines for non-zero inputs.
    // std::cout << "Digits in 0: " << countDigits(0) << std::endl;
    // std::cout << "Digits in -987: " << countDigits(-987) << std::endl;
    return 0;
}