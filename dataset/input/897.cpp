#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        // Semantic Error: bitwise operators vs arithmetic?
        // Let's use `n & 10` again? No.
        
        // Let's use assignment in loop condition?
        // while (n = 0) // Loop doesn't run.
        
        // Let's confuse modulo and division.
        int digit = n / 10; // First digits? 
        // n = 123. digit = 12. 
        // reversed = 0*10 + 12 = 12.
        // n = n % 10 = 3.
        // Next iter: n=3. digit=0. reversed=120. n=3. Infinite loop?
        // No, n update is the key.
        
        // Let's use `n = n % 10`.
        // n=123. digit=12. n=3.
        // n=3. digit=0. n=3.
        // Infinite loop.
        
        // Let's try:
        // reversed = (reversed << 1) + digit; // Bitwise shift (multiply by 2) instead of *10.
        // Semantic: Treating decimal number as binary?
        
        // Let's go with bitwise shift.
        reversed = (reversed << 1) + (n % 10);
        n /= 10;
    }
    
    return original == reversed;
}

int main() {
    int n = 121;
    // reversed = 0 + 1 = 1
    // reversed = 2 + 2 = 4
    // reversed = 8 + 1 = 9
    // 121 != 9.
    
    if (isPalindrome(n)) cout << n << " is a palindrome." << endl;
    else cout << n << " is not a palindrome." << endl;
    return 0;
}
