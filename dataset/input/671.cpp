#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    // Efficiency/Readability Issue: Nested loop O(N^2) just to count?
    // Or maybe iterating 256 times for every character?
    // Let's do nested loop approach: for each char, count it in the whole string.
    // This is O(N^2).
    
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // Overwriting multiple times
        frequency[arr[i]] = count;
    }
}

int main() {
    const char arr[] = "hello";
    int frequency[256] = {0};
    
    findCharacterFrequency(arr, frequency);
    
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            cout << (char)i << ": " << frequency[i] << endl;
        }
    }
    return 0;
}
