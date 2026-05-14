#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    // Efficiency Issue: Nested loop O(N^2).
    // For each char, scan the whole string to count occurrences.
    // Instead of O(N) using frequency array.
    
    if (str == nullptr) return '\0';
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }
        if (count == 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    cout << firstNonRepeating("swiss") << endl;
    return 0;
}
