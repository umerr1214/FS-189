#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int n) {
    if (n < 0) return false;
    if (n == 0) return true;
    if (n % 10 == 0) return false; // Optimization: Ends in 0 (but not 0) cannot be palindrome
    
    int original = n;
    long long reversed = 0; // Use long long to prevent overflow during reversal
    
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}

int main() {
    cout << "121: " << isPalindrome(121) << endl; // 1
    cout << "-121: " << isPalindrome(-121) << endl; // 0
    cout << "10: " << isPalindrome(10) << endl; // 0
    
    return 0;
}
