#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upperCase(char array[]) {
    // Robustness Issue: No NULL check.
    
    int len = strlen(array); // Crash if NULL
    for (int i = 0; i < len; i++) {
        if (i == 0 || array[i - 1] == ' ') {
            array[i] = toupper(array[i]);
        }
        if (i == len - 1 || array[i + 1] == ' ') {
            array[i] = toupper(array[i]);
        }
    }
}

int main() {
    char* arr = NULL;
    // Crash
    // upperCase(arr);
    return 0;
}
