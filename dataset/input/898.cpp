#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int n) {
    // Robustness Issue: Integer overflow for reversed number.
    // If n = 1999999999 (valid int), reversed > INT_MAX.
    // Logic should handle overflow.
    // For palindrome check, if it overflows, it's not equal to original (unless original was already overflowed? no).
    // Actually, signed integer overflow is UB.
    
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        int digit = n % 10;
        // Check overflow? Missing.
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}

int main() {
    // 2147483647 (INT_MAX). Reversed 746... overflows.
    // isPalindrome(2147447412); 
    return 0;
}
