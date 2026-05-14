#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void findDuplicateCharacters(const char arr[], char duplicates[], int& duplicatesSize) {
    if (arr == nullptr || duplicates == nullptr) {
        duplicatesSize = 0;
        return;
    }

    int counts[256] = {0}; // Assuming ASCII
    int k = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        unsigned char c = (unsigned char)arr[i];
        counts[c]++;
    }
    
    // Collect duplicates
    // Requirement says "returns... duplicate characters". Order usually not specified strictly,
    // but often order of first appearance or alphabetical.
    // Iterating 0..255 gives alphabetical order.
    // Iterating array again gives order of appearance.
    // Let's stick to alphabetical/ASCII order for stability.
    
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 1) {
            duplicates[k++] = (char)i;
        }
    }
    duplicatesSize = k;
}

int main() {
    const char arr[] = "programming";
    char duplicates[20];
    int duplicatesSize = 0;
    
    findDuplicateCharacters(arr, duplicates, duplicatesSize);
    
    cout << "Duplicates: ";
    for (int i = 0; i < duplicatesSize; i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    
    return 0;
}
