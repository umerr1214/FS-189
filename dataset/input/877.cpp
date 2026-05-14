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
        if (!isVowel(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'
} // Syntax Error: Missing semicolon

int main() {
    char str[] = "Hello World";
    cout << "Original: " << str << endl;
    removeVowels(str);
    cout << "No Vowels: " << str << endl;
    return 0;
}
