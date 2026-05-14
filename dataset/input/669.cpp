#include <iostream>
#include <cstring>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    // Semantic Error: Using character value as index incorrectly?
    // Actually, `frequency[arr[i]]` is correct if arr[i] is positive char.
    // If char is signed and negative (extended ASCII), this is an OOB access (negative index).
    // This is a semantic error regarding type safety/assumptions.
    
    // Let's make a more obvious semantic error.
    // Treating `frequency` as char array instead of int array?
    // Or confusing index and value.
    
    for (int i = 0; arr[i] != '\0'; i++) {
        // Semantic Error: Using loop index 'i' as the key instead of 'arr[i]'
        // This counts how many times the *position* i appears? No, i is unique.
        // It just increments frequency[0], frequency[1], etc.
        frequency[i]++; 
    }
}

int main() {
    const char arr[] = "hello";
    int frequency[256] = {0};
    
    findCharacterFrequency(arr, frequency);
    
    // Expected: h:1, e:1, l:2, o:1
    // Actual: frequency[0]=1, frequency[1]=1... frequency[4]=1. 
    // Which corresponds to char(0), char(1)... non-printable.
    return 0;
}
