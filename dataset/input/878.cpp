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
    // Logical Error: Missing null terminator at the new end 'j'.
    // The string retains characters from 'j' onwards from the original string.
    // E.g. "Hello" -> "Hlllo" (removes e, o, but 'l','o' remain at end)
}

int main() {
    char str[] = "Hello";
    // Expected: "Hll"
    // Actual: "Hlllo" (garbage tail)
    removeVowels(str);
    cout << "No Vowels: " << str << endl;
    return 0;
}
