#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void upperCase(char array[]) {
    int len = strlen(array);
    for (int i = 0; i < len; i++) {
        // Semantic Error: Confusing character values with pointer offsets?
        // Or using assignment in if condition?
        
        // Let's use assignment in 'if' again? Or maybe comparing array element with string literal?
        // if (array[i] == " ") // compile error
        
        // Let's use bitwise AND instead of logical AND?
        // if ((i == 0) & (array[i-1] == ' ')) ... valid but potentially wrong precedence if complex.
        
        // Let's try: treating the character as an index to the array itself?
        // array[array[i]] = toupper(...); // Semantic misuse if array[i] is a char value
        
        if (i == 0 || array[i - 1] == ' ') {
            // Semantic Error: Assigning the function pointer toupper instead of calling it?
            // array[i] = (char)toupper; // Cast makes it compile but garbage value
            
            // Or maybe:
            array[i] = array[i] + 'A' - 'a'; // Manual toupper assuming lowercase input,
            // but if it's already uppercase or non-alpha, it corrupts it. 
            // The prompt says "input will have all lowercase", so this is technically correct logic manually.
            
            // Let's do something clearly wrong semantically.
            // Treating the array as an integer array?
            // ((int*)array)[i] = ...
            
            // Let's stick to the 'assignment in condition' classic because it's subtle and common.
            // if (array[i] = ' ') // Sets current char to space and returns true (32)
            
            // Let's try:
            if (array[i+1] = ' ') { // Sets next char to space!
                 array[i] = toupper(array[i]);
            }
        }
    }
}

int main() {
    char arr[100] = "hello world";
    cout << "Before: " << arr << endl;
    
    upperCase(arr); // Will modify string weirdly
    
    cout << "After: " << arr << endl;
    return 0;
}
