#include <iostream>
#include <cstring>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) return false;
    if (strlen(str1) != strlen(str2)) return false;
    
    int count[256] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str1[i];
        count[c]++;
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str2[i];
        count[c]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    
    return true;
}

int main() {
    const char* s1 = "listen";
    const char* s2 = "silent";
    cout << "Is anagram: " << areAnagrams(s1, s2) << endl;
    
    cout << "Is anagram: " << areAnagrams("hello", "world") << endl;
    
    cout << "Is anagram: " << areAnagrams(NULL, "a") << endl;
    
    return 0;
}
