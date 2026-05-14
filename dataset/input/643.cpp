#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findLongestPalindrome(const char arr[]) {
    int n = strlen(arr);
    if (n == 0) return 0;
    
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool isPalindrome = true;
            for (int k = 0; k < (j - i + 1) / 2; k++) {
                if (arr[i + k] != arr[j - k]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
            }
        }
    }
    return maxLength
} // Syntax Error: Missing semicolon

int main() {
    const char arr[] = "babad";
    cout << "Longest Palindrome Length: " << findLongestPalindrome(arr) << endl;
    return 0;
}
