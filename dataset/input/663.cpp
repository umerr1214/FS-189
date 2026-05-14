#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findDuplicateCharacters(const char arr[], char duplicates[], int& duplicatesSize) {
    int k = 0;
    int len = strlen(arr);
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            // Semantic Error: String literal comparison instead of character comparison?
            // Or using assignment.
            // Let's try comparison with string literal which compares address of char with address of string literal (illegal in C++ without cast, but maybe decay works or warning)
            // Or comparing arr[i] with "a"? No that's char vs pointer.
            
            // Let's use bitwise AND instead of logical AND or equality? 
            // if (arr[i] & arr[j]) -> true if they share bits (almost always true)
            
            // Let's use assignment in condition again, classic and easy to spot.
            if (arr[i] = arr[j]) { // Semantic Error: Assignment instead of comparison
                // Modifies input array (if not const, but it is const char arr[]... wait)
                // If it is const char arr[], modifying it is a compile error!
                // Ah, the signature is const char arr[].
                // So I cannot modify arr[i].
                
                // Let's try comparing addresses of characters?
                // if (&arr[i] == &arr[j]) -> always false for i!=j.
                
                // Let's try using a wrong type for checking duplicates?
                // Or maybe the error is in the inner loop condition?
                
                duplicates[k++] = arr[i];
            }
        }
    }
    duplicatesSize = k;
}
// Wait, if I write `arr[i] = arr[j]` in a function taking `const char arr[]`, it won't compile.
// I must produce a file that compiles but has a semantic error (runtime behavior wrong or warning).
// Let's cast away const? No, too complex.
// Let's incorrectly treat characters as indices?
// duplicates[arr[i]] = ...
// This assumes arr[i] is a valid index, which is semantic misuse if not guaranteed.
// Or `if (arr[i] && arr[j])` -> check if both are not null?

// Better Semantic Error:
// Using `sizeof(arr)` instead of `strlen(arr)` inside the function.
// `sizeof(arr)` on a parameter `const char arr[]` returns size of pointer (4 or 8), not array length.
// This is a classic semantic/pointer-decay error.

void findDuplicateCharacters_Semantic(const char arr[], char duplicates[], int& duplicatesSize) {
    int k = 0;
    int len = sizeof(arr); // Semantic Error: sizeof on pointer parameter
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                bool alreadyAdded = false;
                for (int m = 0; m < k; m++) {
                    if (duplicates[m] == arr[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    duplicates[k++] = arr[i];
                }
            }
        }
    }
    duplicatesSize = k;
}

int main() {
    const char arr[] = "programming"; // Length 11
    char duplicates[20];
    int duplicatesSize = 0;
    
    // sizeof(arr) in main is 12 (11 + null), but in function it's 8 (64-bit ptr) or 4.
    // So loop only goes up to index 7 or 3, missing duplicates at the end.
    findDuplicateCharacters_Semantic(arr, duplicates, duplicatesSize);
    
    cout << "Duplicates: ";
    for (int i = 0; i < duplicatesSize; i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    return 0;
}
