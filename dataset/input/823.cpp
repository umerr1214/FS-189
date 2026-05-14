#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    if (str == nullptr) return '\0';
    
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0'
} // Syntax Error: Missing semicolon

int main() {
    const char* str = "swiss";
    char result = firstNonRepeating(str);
    if (result != '\0') {
        cout << "First non-repeating: " << result << endl;
    } else {
        cout << "All characters repeat." << endl;
    }
    return 0;
}
