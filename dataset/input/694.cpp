#include <iostream>
#include <cstring>
using namespace std;

int countCharacterOccurrences(const char arr[], char target) {
    // Robustness Issue: No NULL check.
    
    int count = 0;
    // Crash if arr is NULL
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    const char* arr = NULL;
    // countCharacterOccurrences(arr, 'a');
    return 0;
}
