#include <iostream>

bool isPalindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are generally not considered palindromes
    }
    int originalNum = num;
    int reversedNum = 0;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    int num;
    std::cout << "Enter an integer: " // Syntax Error: Missing semicolon here
    std::cin >> num;
    if (isPalindrome(num)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}