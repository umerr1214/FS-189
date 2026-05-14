#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        // Semantic Error: Accessing array using char value as index?
        // arr[arr[i]] = ...
        
        // Or comparing char with " ".
        // if (arr[i] == " ") // Error
        
        // Let's use the classic:
        // if (arr[i] & ' ') // Checks bitwise. Space is 32 (0x20). 
        // 'a' is 97 (0x61). 0x61 & 0x20 is true.
        // So 'a' is treated as space? 
        // 'A' (65, 0x41) -> true.
        // '@' (64, 0x40) -> false.
        
        // Let's try:
        if (i == 0 || (arr[i-1] & ' ')) { // Semantic error: bitwise check instead of equality
             // ' ' is 0x20. If arr[i-1] has 0x20 bit set (e.g. 'a', 'c', 'e'...), it thinks it's start of word.
             arr[i] = toupper(arr[i]);
        }
        
        if (i == len-1 || (arr[i+1] & ' ')) {
             arr[i] = toupper(arr[i]);
        }
    }
}

int main() {
    char arr[100] = "hello";
    // h: i=0 -> Upper H.
    // e: i=1. prev='h'(0x68). 0x68 & 0x20 = 0x20 (True). Becomes E.
    // l: i=2. prev='e'(0x65). True. Becomes L.
    // ... "HELLO"
    
    // Expected: "HellO"
    // Actual: "HELLO" (likely)
    
    convertStartEndToUpper(arr);
    cout << "After: " << arr << endl;
    return 0;
}
