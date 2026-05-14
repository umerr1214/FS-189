#include <iostream>
#include <cstring>
using namespace std;

int findLongestPalindrome(const char arr[]) {
    // Readability/Efficiency Issue: Brute force O(N^3)
    // Nested loops (i, j) = O(N^2), inner palindrome check O(N) => Total O(N^3).
    // Can be improved to O(N^2) using center expansion or DP, or O(N) using Manacher's.
    
    int n = strlen(arr);
    if (n == 0) return 0;
    
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Check if substring arr[i...j] is palindrome
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
    return maxLength;
}

int main() {
    const char arr[] = "babad";
    cout << "Longest Palindrome Length: " << findLongestPalindrome(arr) << endl;
    return 0;
}
