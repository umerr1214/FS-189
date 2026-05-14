#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convertStartEndToUpper(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        // Start of word
        if (i == 0 || arr[i - 1] == ' ') {
            arr[i] = toupper(arr[i]);
        }
        // End of word
        if (i == len - 1 || arr[i + 1] == ' ') {
            arr[i] = toupper(arr[i]);
        }
    }
}

int main() {
    char arr[100] = "hello world again";
    cout << "Before: " << arr << endl;
    
    convertStartEndToUpper(arr) // Syntax Error: Missing semicolon
    
    cout << "After: " << arr << endl;
    return 0;
}
