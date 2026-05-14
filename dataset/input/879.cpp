#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void removeVowels(char* str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        // Semantic Error: Checking if 'str' itself is vowel?
        // if (isVowel((char)str)) // Cast pointer to char? Nonsense.
        
        // Let's use:
        // if (!isVowel(i)) // Checking index instead of value?
        
        // Let's use assignment in array access?
        
        // Let's use:
        if (!isVowel(&str[i])) { // Semantic Error: Passing address (char*) to char function
            // isVowel takes char. Passing char* is invalid conversion.
            // Wait, I need it to compile.
            
            // Let's cast it to char?
            // if (!isVowel((char)&str[i]))
            // This takes the lower byte of the address.
            // Random behavior.
            
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Helper to make it compile with semantic error (by changing signature of isVowel to accept anything or cast)
bool isVowel_Semantic(long long val) {
    return false; // Dummy
}

void removeVowels_Semantic(char* str) {
     int i = 0, j = 0;
    while (str[i] != '\0') {
        // Semantic: Passing pointer to function expecting char logic
        if (!isVowel_Semantic((long long)&str[i])) { 
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[] = "Hello";
    removeVowels_Semantic(str);
    return 0;
}
