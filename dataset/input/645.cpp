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
            // Semantic Error: confusion of pointers/arrays? 
            // Or maybe using a char as a pointer?
            // Let's use assignment in 'if' again? No, used that.
            // Let's return the pointer to the substring instead of length, but return type is int?
            // That would be a type error or warning (address to int).
            
            // Let's try: treating the char value as the length loop limit
            for (int k = 0; k < arr[i]; k++) { // Semantic misuse: using char value as loop count
                 if (arr[i+k] != arr[j-k]) { // Likely OOB or nonsense
                     isPalindrome = false;
                     break;
                 }
            }
            
            if (isPalindrome && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength;
}

int main() {
    const char arr[] = "aba";
    // arr[0] is 'a' (97). Loop runs 97 times... definitely wrong semantics.
    cout << "Longest Palindrome Length: " << findLongestPalindrome(arr) << endl;
    return 0;
}
