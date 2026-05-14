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
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    std::cout << "Digits in 12345: " << countDigits(12345) << std::endl;
    std::cout << "Digits in 0: " << countDigits(0) << std::endl;
    std::cout << "Digits in -987: " << countDigits(-987) << std::endl // Missing semicolon here
    return 0;
}