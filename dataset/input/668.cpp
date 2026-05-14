#include <iostream>
#include <cstring>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    // Logical Error: Resetting frequency inside the loop
    // This will cause the count to always be 1 for the last occurrence, or just wrong.
    
    for (int i = 0; arr[i] != '\0'; i++) {
        frequency[arr[i]] = 0; // Resetting count!
        frequency[arr[i]]++;
    }
}

int main() {
    const char arr[] = "hello";
    int frequency[256] = {0};
    
    findCharacterFrequency(arr, frequency);
    
    // Expected: l: 2
    // Actual: l: 1 (because it reset at the second 'l')
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            cout << (char)i << ": " << frequency[i] << endl;
        }
    }
    return 0;
}
