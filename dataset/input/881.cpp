#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void removeVowels(char* str) {
    // Efficiency/Readability: Using std::string for simple char array manipulation.
    // Allocates memory, copies data, then copies back.
    // In-place O(1) space is better.
    
    if (str == nullptr) return;
    
    string s = str;
    string res = "";
    for (char c : s) {
        if (!isVowel(c)) {
            res += c;
        }
    }
    strcpy(str, res.c_str());
}

int main() {
    char str[] = "Hello World";
    removeVowels(str);
    cout << str << endl;
    return 0;
}
