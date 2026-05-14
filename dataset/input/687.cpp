#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char arr[], const char target[], const char replacement[]) {
    // Semantic Error: Assuming arr is a string literal pointer? 
    // Or treating characters as strings for strcat?
    
    int targetLen = strlen(target);
    int repLen = strlen(replacement);
    
    char buffer[1000];
    buffer[0] = '\0';
    
    int i = 0;
    int arrLen = strlen(arr);
    
    while (i < arrLen) {
        if (strncmp(&arr[i], target, targetLen) == 0) {
            strcat(buffer, replacement);
            i += targetLen;
        } else {
            // Semantic Error: Passing a char to strcat which expects char*
            // strcat(buffer, arr[i]); // Compile error
            
            // Let's use assignment of char* to char?
            // buffer[strlen(buffer)] = replacement; // Error
            
            // Let's use a pointer to the character in 'arr' but treat it as a string
            // It effectively concatenates the *rest of the string* starting at i
            // instead of just one char.
            strcat(buffer, &arr[i]); // Concatenates everything from i to end
            break; // And exits? If we don't break, it's infinite loop or repeats.
            // If we assume the intention was "append char", this logic "append rest" is semantic misuse.
        }
    }
    strcpy(arr, buffer);
}

int main() {
    char arr[100] = "hello world";
    replaceSubstring(arr, "world", "universe");
    // "hello universe" -> Correct?
    // Wait, first iteration: 'h' != 'w'. Else branch: appends "hello world". Buffer: "hello world".
    // Loop breaks. Result "hello world". Replacement didn't happen because we appended rest immediately.
    
    // Test case: "a world" -> "a" != "world". Appends "a world". Result "a world".
    // It basically never replaces unless target is at start.
    
    cout << "Result: " << arr << endl;
    return 0;
}
