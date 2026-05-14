#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed
} // Syntax Error: Missing semicolon

int main() {
    int n = 12321;
    if (isPalindrome(n)) cout << n << " is a palindrome." << endl;
    else cout << n << " is not a palindrome." << endl;
    return 0;
}
