#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void reverseWords(char arr[]) {
    int n = strlen(arr);
    
    // Semantic Error: Using pointer subtraction incorrectly or swapping wrong types?
    // Let's swap pointers instead of characters.
    // arr is a pointer to the first char.
    // If we try to swap `arr` itself inside the function, it's a local copy of the pointer, so it does nothing to caller.
    // But we need to modify content.
    
    // Let's try: treating the char array as an array of int?
    // Or maybe using `sizeof` on pointer again?
    // Let's use `sizeof` again as it's a common semantic issue in C-style string functions.
    
    int len = sizeof(arr); // Semantic Error: Returns size of pointer (4/8), not string length
    
    reverse(arr, arr + len); // Only reverses first 4 or 8 characters
    
    // ... rest of logic ...
}

int main() {
    char arr[] = "A very long sentence to demonstrate the error";
    reverseWords(arr);
    
    cout << "Reversed: " << arr << endl;
    return 0;
}
