#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    // Robustness Issue: Buffer overflow in local buffer.
    // The replacement string might make the result much longer than 1000.
    // Also no NULL checks.
    
    if (arr == NULL || target == NULL || replacement == NULL) return; // Added null check but buffer is unsafe
    
    int targetLen = strlen(target);
    int repLen = strlen(replacement);
    
    char buffer[10]; // Very small buffer to trigger overflow easily
    buffer[0] = '\0';
    
    int i = 0;
    int arrLen = strlen(arr);
    
    while (i < arrLen) {
        if (strncmp(&arr[i], target, targetLen) == 0) {
            strcat(buffer, replacement); // Overflow if buffer full
            i += targetLen;
        } else {
            int len = strlen(buffer);
            if (len < 9) { // minimal check
                buffer[len] = arr[i];
                buffer[len + 1] = '\0';
            }
            // If full, silently truncates or overflows if check wasn't there
            // But 'strcat' above has no check!
            i++;
        }
    }
    strcpy(arr, buffer);
}

int main() {
    char arr[100] = "short";
    // "short" -> "very long replacement string that overflows buffer"
    replaceSubstring(arr, "short", "very long replacement string that overflows buffer");
    return 0;
}
