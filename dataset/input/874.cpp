#include <iostream>
#include <cstring>
using namespace std;

bool isSubsequence(const char* s1, const char* s2) {
    // Robustness Issue: No NULL check.
    
    // Crash if s1 or s2 is NULL
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return s1[i] == '\0';
}

int main() {
    // Crash
    // isSubsequence(NULL, "abc");
    return 0;
}
