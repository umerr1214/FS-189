#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findLongestPalindrome(const char arr[]) {
    if (arr == nullptr) return 0;
    
    int n = strlen(arr);
    if (n == 0) return 0;
    
    int maxLength = 1;
    
    // Expand Around Center approach O(N^2)
    for (int i = 0; i < n; i++) {
        // Odd length palindromes (center is i)
        int l = i, r = i;
        while (l >= 0 && r < n && arr[l] == arr[r]) {
            if (r - l + 1 > maxLength) {
                maxLength = r - l + 1;
            }
            l--;
            r++;
        }
        
        // Even length palindromes (center is between i and i+1)
        l = i; r = i + 1;
        while (l >= 0 && r < n && arr[l] == arr[r]) {
            if (r - l + 1 > maxLength) {
                maxLength = r - l + 1;
            }
            l--;
            r++;
        }
    }
    return maxLength;
}

int main() {
    const char arr1[] = "babad";
    cout << "Length: " << findLongestPalindrome(arr1) << endl;
    
    const char arr2[] = "cbbd";
    cout << "Length: " << findLongestPalindrome(arr2) << endl;

    const char* arr3 = NULL;
    cout << "Length: " << findLongestPalindrome(arr3) << endl;
    
    return 0;
}
