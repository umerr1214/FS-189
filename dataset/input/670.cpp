#include <iostream>
#include <cstring>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    // Robustness Issue: No NULL check.
    // Also, signed char issues if high-bit characters used -> negative index!
    // And no check for frequency array size (though we can't really check it).
    
    // Crash on NULL
    for (int i = 0; arr[i] != '\0'; i++) {
        // Robustness: Potential negative index if char is signed and > 127
        frequency[arr[i]]++; 
    }
}

int main() {
    const char* arr = NULL;
    int freq[256] = {0};
    // Crash
    // findCharacterFrequency(arr, freq);
    
    // Negative index crash (potentially)
    char signedChar[] = {(char)200, '\0'};
    // findCharacterFrequency(signedChar, freq);
    
    return 0;
}
