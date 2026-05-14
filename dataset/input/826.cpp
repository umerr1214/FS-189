#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    // Robustness Issue: No NULL check.
    
    int count[256] = {0};
    
    // Crash if str is NULL
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++; // Signed char issue if extended ASCII
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    // Crash
    // firstNonRepeating(NULL);
    return 0;
}
