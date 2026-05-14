#include <iostream>
#include <cmath> // For std::abs
#include <string> // For std::to_string in main output

// Function to check if a number is a palindrome.
// Robustness Issue: This implementation incorrectly handles negative numbers.
// It converts negative numbers to their absolute value before checking,
// meaning numbers like -121 will be considered palindromes.
// Most definitions of number palindromes consider the sign, making -121 not a palindrome.
bool isPalindrome(int num) {
    if (num < 0) {
        // This line is the source of the robustness issue for negative numbers.
        // For example, if num is -121, it becomes 121, leading to a 'true' result.
        // Note: std::abs(INT_MIN) can result in INT_MIN on some systems (two's complement),
        // but for other negative numbers, it correctly makes them positive.
        num = std::abs(num);
    }
    
    // 0 is considered a palindrome.
    // The loop below will correctly handle num = 0, setting originalNum = 0, reversedNum = 0.
    // So, no explicit check for num == 0 is strictly needed here, but it's often included for clarity.

    int originalNum = num;
    long long reversedNum = 0; // Using long long to prevent overflow of reversedNum for large positive inputs,
                               // ensuring the primary robustness issue remains the negative number handling.

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() {
    int userInput;
    std::cout << "Enter an integer: ";
    std::cin >> userInput;

    if (isPalindrome(userInput)) {
        std::cout << userInput << " is a palindrome." << std::endl;
    } else {
        std::cout << userInput << " is not a palindrome." << std::endl;
    }

    return 0;
}