#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    if (strlen(str1) != strlen(str2)) return false;
    
    int count[256] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i]]++;
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    
    return true
} // Syntax Error: Missing semicolon

int main() {
    const char* s1 = "listen";
    const char* s2 = "silent";
    if (areAnagrams(s1, s2)) cout << "Anagrams" << endl;
    else cout << "Not Anagrams" << endl;
    return 0;
}
