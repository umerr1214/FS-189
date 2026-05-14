#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void removeDuplicates(char arr[]) {
    int n = strlen(arr);
    
    // Semantic Error: Confusing pointer arithmetic or array indexing logic?
    // Let's incorrectly assume we can resize the static array? 
    // No, that's not possible.
    
    // Let's use `sizeof` on pointer again? 
    // Or maybe treating characters as pointers again?
    
    // Let's try: Using assignment in comparison again?
    // Or maybe using `delete` on a stack array (semantic error, invalid free)?
    // Or returning a local pointer? (return type is void).
    
    // Let's use the loop index 'i' as the character value to store.
    // arr[index++] = i;
    // This fills the array with 0, 1, 2... which is semantic nonsense.
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == i) {
            arr[index++] = (char)i; // Semantic Error: Storing index instead of value
        }
    }
    arr[index] = '\0';
}

int main() {
    char arr[] = "abc";
    removeDuplicates(arr);
    // arr becomes {0, 1, 2, \0} (non-printable)
    cout << "Unique characters: " << arr << endl; 
    return 0;
}
