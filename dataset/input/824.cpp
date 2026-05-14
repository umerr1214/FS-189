#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    if (str == nullptr) return '\0';
    
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
    }
    
    // Logical Error: Iterating the count array (0..255) instead of the string.
    // This returns the *alphabetically* first non-repeating character,
    // not the *first in the string*.
    
    for (int i = 0; i < 256; i++) {
        if (count[i] == 1) {
            return (char)i;
        }
    }
    
    return '\0';
}

int main() {
    const char* str = "stress";
    // Expected: 't' (s repeats, t is first unique)
    // Actual: 'e' (e is unique and alphabetically before t and r)
    // s:3, t:1, r:1, e:1.
    // Alphabetical order: e, r, s, t.
    // 'e' comes first in loop 0..255.
    
    char result = firstNonRepeating(str);
    if (result != '\0') {
        cout << "First non-repeating: " << result << endl;
    } else {
        cout << "All characters repeat." << endl;
    }
    return 0;
}
