#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    // Efficiency/Readability:
    // Recursion O(M) stack depth (M = length of s2).
    // Or constructing strings.
    // Iterative is O(1) space.
    
    if (s1 == nullptr || s2 == nullptr) return false;
    
    if (*s1 == '\0') return true;
    if (*s2 == '\0') return false;
    
    if (*s1 == *s2) {
        return isSubsequence(s1 + 1, s2 + 1);
    }
    return isSubsequence(s1, s2 + 1);
    
    // This is valid but less efficient (stack usage) than loop for simple pointer arithmetic.
}

int main() {
    cout << isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
