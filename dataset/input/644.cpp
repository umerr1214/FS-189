#include <iostream>
#include <cstring>
using namespace std;

int findLongestPalindrome(const char arr[]) {
    int n = strlen(arr);
    if (n == 0) return 0;
    
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool isPalindrome = true;
            // Logical Error: Loop range for checking palindrome is incorrect or offset is wrong
            // Should check from k=0 to (len/2).
            // Here, let's make a mistake in the palindrome check logic.
            // It only checks the first and last character of the substring, assuming that's enough.
            
            if (arr[i] != arr[j]) { // Only checking ends
                isPalindrome = false; 
            }
            
            // This considers "abcda" as a palindrome because 'a' == 'a'
            if (isPalindrome && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength;
}

int main() {
    const char arr[] = "abcda"; 
    // Should be 1 (since 'a', 'b', 'c', 'd' are palindromes of length 1)
    // But logical error will say 5 ("abcda") because ends match.
    cout << "Longest Palindrome Length: " << findLongestPalindrome(arr) << endl;
    return 0;
}
