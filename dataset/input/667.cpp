#include <iostream>
#include <cstring>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    // Assuming frequency array is initialized to 0 by caller or we should do it?
    // Usually caller's responsibility in C++ unless specified.
    // Let's assume initialized.
    
    for (int i = 0; arr[i] != '\0'; i++) {
        frequency[arr[i]]++;
    }
} // Syntax Error: Missing semicolon

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
