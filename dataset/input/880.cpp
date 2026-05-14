#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void removeVowels(char* str) {
    // Robustness Issue: No NULL check.
    
    // Crash if str is NULL
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    // Crash
    // removeVowels(NULL);
    return 0;
}
