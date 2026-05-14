#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    int targetLen = strlen(target);
    int repLen = strlen(replacement);
    
    char buffer[1000];
    buffer[0] = '\0';
    
    int i = 0;
    int arrLen = strlen(arr);
    
    while (i < arrLen) {
        if (strncmp(&arr[i], target, targetLen) == 0) {
            strcat(buffer, replacement);
            // Logical Error: Only incrementing by 1 instead of targetLen
            // This causes recursive replacement if replacement contains target prefix,
            // or just garbage output like "hiello..."
            i++; 
        } else {
            int len = strlen(buffer);
            buffer[len] = arr[i];
            buffer[len + 1] = '\0';
            i++;
        }
    }
    strcpy(arr, buffer);
}

int main() {
    char arr[100] = "hello";
    // Expected: "hi"
    // Actual: "hiello" (replaces 'h', then 'e' remains, etc.) or worse if overlapping
    replaceSubstring(arr, "h", "H"); // "Hello" -> "Hello" (infinite loop if H contains h?) No case sensitive.
    // Let's try: "aa" -> "b" in "aaaa"
    // Expected: "bb"
    // Actual: "baaa" -> finds 'aa' at 0, adds 'b', moves to 1. finds 'aa' at 1, adds 'b'...
    
    strcpy(arr, "aaaa");
    replaceSubstring(arr, "aa", "b");
    cout << "Result: " << arr << endl;
    return 0;
}
