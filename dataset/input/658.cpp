#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    // Robustness Issue: No check for NULL pointer.
    // Iterating arr[i] will crash if arr is NULL.
    
    int maxZeros = 0;
    int currentZeros = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '0') {
            currentZeros++;
        } else {
            maxZeros = max(maxZeros, currentZeros);
            currentZeros = 0;
        }
    }
    maxZeros = max(maxZeros, currentZeros);
    return maxZeros;
}

int main() {
    const char* arr = NULL;
    // Crash
    // findConsecutiveZeros(arr);
    return 0;
}
