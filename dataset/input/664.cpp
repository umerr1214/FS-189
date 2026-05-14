#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findDuplicateCharacters(const char arr[], char duplicates[], int& duplicatesSize) {
    // Robustness Issue: No NULL check for arr or duplicates.
    // Also no check for buffer overflow in duplicates array (we don't know its size).
    
    // If arr is NULL -> Segfault
    int len = strlen(arr); 
    
    int k = 0;
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
                    duplicates[k++] = arr[i]; // Potential buffer overflow if duplicates is small
                }
            }
        }
    }
    duplicatesSize = k;
}

int main() {
    const char* arr = NULL;
    char duplicates[20];
    int duplicatesSize = 0;
    
    // Crash
    // findDuplicateCharacters(arr, duplicates, duplicatesSize);
    return 0;
}
