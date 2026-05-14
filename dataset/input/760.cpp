#include <iostream>
#include <cstring>
using namespace std;

void encrypt(char arr[]) {
    // Robustness Issue: No NULL check.
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        // Robustness: Potential overflow of char.
        // char is usually -128 to 127. If 'z' (122) + index (10) = 132 -> overflow to negative.
        // This is actually valid behavior for char arithmetic (wraparound), but usually
        // "encrypt" implies printable characters or safe handling.
        // If we want robustness, we might want to mod 256 or something, but the prompt
        // implies simple addition.
        // Main robustness issue: NULL pointer.
        
        arr[i] += i;
    }
}

void decrypt(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        arr[i] -= i;
    }
}

int main() {
    char* arr = NULL;
    // Crash
    // encrypt(arr);
    return 0;
}
