#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    // Robustness Issue: No NULL check.
    
    int len = strlen(arr); // Crash if NULL
    for (int i = 0; i < len; i++) {
        // Robustness: arr[i-1] when i=0 is OOB (negative index).
        // Wait, loop starts at 0.
        // We checked `i==0 || arr[i-1]`. Due to short-circuit, `i==0` protects `arr[i-1]`.
        // BUT if we swap them? `arr[i-1] == ' ' || i == 0` -> OOB access!
        
        if (arr[i-1] == ' ' || i == 0) { // OOB Access at i=0
             arr[i] = toupper(arr[i]);
        }
        
        if (i == len - 1 || arr[i + 1] == ' ') {
            arr[i] = toupper(arr[i]);
        }
    }
}

int main() {
    char arr[100] = "hello";
    convertStartEndToUpper(arr); // Undefined behavior (reading before array)
    return 0;
}
