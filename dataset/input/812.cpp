#include <iostream>
#include <cstring>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    if (strlen(str1) != strlen(str2)) return false;
    
    int count[256] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i]]++;
    }
    
    // Logical Error: Incrementing instead of decrementing for second string
    // This accumulates counts instead of cancelling them out.
    // Result will be non-zero unless both strings are empty.
    
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i]]++; 
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    
    return true;
}

int main() {
    const char* s1 = "listen";
    const char* s2 = "silent";
    // Expected: Anagrams (True)
    // Actual: Not Anagrams (False) because counts double
    if (areAnagrams(s1, s2)) cout << "Anagrams" << endl;
    else cout << "Not Anagrams" << endl;
    return 0;
}
