#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    if (n < 0) return false;
    
    int original = n;
    int reversed = 0;
    
    while (n > 0) {
        int digit = n % 10;
        // Logical Error: Incorrect update of reversed number.
        // Adding digit instead of appending it (reversed * 10 + digit).
        // Or incorrect loop update.
        
        reversed += digit; // Sums digits instead of reversing
        n /= 10;
    }
    
    return original == reversed;
}

int main() {
    int n = 121;
    // Expected: True (121 == 121)
    // Actual: reversed = 1+2+1 = 4. 121 != 4. False.
    // Wait, let's try n=1. reversed=1. True.
    // n=121. reversed=4. False.
    if (isPalindrome(n)) cout << n << " is a palindrome." << endl;
    else cout << n << " is not a palindrome." << endl;
    return 0;
}
