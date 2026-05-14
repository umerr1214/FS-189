#include <iostream>
#include <cstring>
using namespace std;

char firstNonRepeating(const char* str) {
    if (str == nullptr) return '\0';
    
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        // Semantic Error: Using assignment in array index again?
        // Or using bitwise NOT.
        
        // Let's use `count[str]++` type error (pointer to int).
        
        // Let's use `count[&str[i]]`.
        
        // Let's use simple assignment in condition inside the second loop?
        // No, first loop needs semantic error.
        
        // How about using `sizeof` on str?
        // for (int i=0; i < sizeof(str); i++) // Loop runs 4/8 times.
        // This is a semantic error (sizeof pointer).
        // Let's assume loop condition is `str[i]`.
        
        // Let's increment the pointer `str` itself inside the array index?
        // count[*str++]++; 
        // This modifies the local pointer `str`.
        // Then in the second loop, `str` points to end of string (or middle).
        // So second loop `for (int i=0; str[i]...` starts from where we left off (null terminator).
        // So second loop doesn't run. Returns '\0'.
        
        count[*str++]++; 
    }
    
    // str now points to '\0'
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    const char* s = "swiss"; // const char* but function takes const char* (passed by value).
    // The pointer *copy* is modified.
    char result = firstNonRepeating(s);
    // Returns '\0' because second loop sees empty string.
    
    if (result != '\0') cout << result << endl;
    else cout << "None" << endl;
    return 0;
}
