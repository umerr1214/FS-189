#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void removeVowels(char* str) {
    if (str == nullptr) return;
    
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
    char str1[] = "Hello World";
    removeVowels(str1);
    cout << "Result: " << str1 << endl;
    
    char str2[] = "aeiou";
    removeVowels(str2);
    cout << "Result: " << str2 << endl; // Empty
    
    removeVowels(NULL); // Safe
    
    return 0;
}
