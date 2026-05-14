#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void runLengthEncode(const char* input, char* output) {
    // Robustness Issue: No NULL check.
    // Also, no check for output buffer size (impossible without size param).
    // Let's focus on NULL check.
    
    int len = strlen(input); // Crash if input is NULL
    int k = 0;
    
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[k++] = input[i]; // Crash if output is NULL
        
        char countStr[10];
        sprintf(countStr, "%d", count);
        for (int j = 0; countStr[j] != '\0'; j++) {
            output[k++] = countStr[j];
        }
    }
    output[k] = '\0';
}

int main() {
    // Crash
    // runLengthEncode(NULL, NULL);
    return 0;
}
