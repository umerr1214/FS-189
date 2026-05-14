#include <iostream>
#include <cstring>
using namespace std;

void findCharacterFrequency(const char arr[], int frequency[]) {
    if (arr == nullptr || frequency == nullptr) {
        return;
    }

    // Initialize frequency array to 0 is often expected if function claims to find frequency
    // But since it's passed in, we should clarify. Assuming we should zero it out first or just add?
    // Usually "find frequency" implies starting from 0.
    // However, if we don't know the size of frequency array (assumed 256), clearing it is unsafe if caller passed smaller.
    // The safest "correct" version compliant with C++ arrays simply iterates. 
    // We assume caller provides zeroed array or valid state.
    
    for (int i = 0; arr[i] != '\0'; i++) {
        unsigned char c = (unsigned char)arr[i]; // Cast to unsigned to handle extended ASCII safely
        frequency[c]++;
    }
}

int main() {
    const char arr[] = "hello";
    int frequency[256] = {0}; // Initialize to 0
    
    findCharacterFrequency(arr, frequency);
    
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            cout << (char)i << ": " << frequency[i] << endl;
        }
    }
    
    // Robustness test
    findCharacterFrequency(NULL, frequency); // Should safe return
    
    return 0;
}
