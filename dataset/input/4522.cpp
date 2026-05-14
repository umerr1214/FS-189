#include <iostream>

bool isPalindrome(int num) {
    if (num < 0) {
        return false;
    }
    int originalNum = num;
    int reversedNum = 0;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum // Missing semicolon here
}

int main() {
    // This file is designed to have a syntax error and will not compile.
    // The driver code in the JSON will attempt to compile and run this.
    // No specific logic for main is needed here beyond a basic structure.
    return 0;
}