#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    if (str == nullptr) return '\0';
    
    int count[256] = {0};
    
    // First pass: count frequencies
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i]; // Handle signed chars
        count[c]++;
    }
    
    // Second pass: find first with count 1
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (count[c] == 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    const char* s1 = "swiss";
    cout << "First unique in '" << s1 << "': " << firstNonRepeating(s1) << endl;
    
    const char* s2 = "aabbcc";
    char r2 = firstNonRepeating(s2);
    if (r2 == '\0') cout << "No unique in '" << s2 << "'" << endl;
    else cout << r2 << endl;
    
    firstNonRepeating(NULL);
    
    return 0;
}
