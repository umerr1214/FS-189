#include <iostream>

bool isPalindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are typically not considered palindromes
    }
    if (num == 0) {
        return true; // 0 is a palindrome
    }

    // Logical error: The original 'num' is modified during the reversal process.
    // When the loop finishes, 'num' will be 0.
    // The comparison 'num == reversedNum' at the end will almost always be false
    // because 'num' no longer holds its original value.
    int reversedNum = 0;
    while (num > 0) { // 'num' is modified in this loop
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    
    // This comparison is incorrect because 'num' has been reduced to 0.
    return num == reversedNum; 
}

int main() {
    // Driver code will be in JSON to test the isPalindrome function.
    return 0;
}