#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;
            // Logical Error: Resetting j index? Or incrementing j inside if only?
            // If we increment j only when match found, we get infinite loop if mismatch.
            // j++; 
        } else {
            j++;
        }
        // Correct logic increments j always.
        // Error: Swapped logic? Or incrementing i regardless?
        
        // Let's implement: increment `i` always, increment `j` only on match.
        // This checks if s2 is subsequence of s1 (reversed roles) or just nonsense.
    }
    
    // Let's try:
    // while (s1[i] && s2[j]) {
    //    if (s1[i] == s2[j]) j++; // Advance in s2
    //    i++; // Always advance in s1
    // }
    // This checks if s2 is subsequence of s1.
    // If s1="abc", s2="ahbgdc". i advances. j advances if match.
    // "a"=="a" -> j=1. "b"!="h".
    // It fails immediately.
    
    // Let's go with: Only increment j when match found? Infinite loop if mismatch.
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } 
        // Missing else j++
        // If mismatch, loop spins forever on same j (unless we add else block).
        // If we don't increment j on mismatch, it's infinite loop.
    }
    return s1[i] == '\0';
}

int main() {
    // Expected: 1 (True)
    // Actual: Infinite loop or crash (Time Limit Exceeded)
    cout << "Is 'abc' subseq of 'ahbgdc'? " << isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
