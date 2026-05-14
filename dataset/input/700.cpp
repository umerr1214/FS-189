#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalizeWords(char arr[]) {
    // Robustness Issue: No NULL check.
    // Accessing arr[0] crashes.
    
    bool newWord = true;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (isspace(arr[i])) {
            newWord = true;
        } else if (newWord) {
            arr[i] = toupper(arr[i]);
            newWord = false;
        } else {
            arr[i] = tolower(arr[i]);
        }
    }
}

int main() {
    char* arr = NULL;
    // Crash
    // capitalizeWords(arr);
    return 0;
}
