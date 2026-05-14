#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    int maxZeros = 0;
    int currentZeros = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == '0') {
            currentZeros++;
        } else {
            // Logical Error: Failing to update maxZeros when sequence breaks
            // Just resetting currentZeros without saving the max.
            currentZeros = 0; 
        }
    }
    // Also forgot to check at the end if the array ends with zeros
    // maxZeros = max(maxZeros, currentZeros); 
    
    return maxZeros; // Will always return 0 (initialized value) unless logic is somewhere else
}

int main() {
    const char arr[] = "10010001";
    // Expected: 3
    // Actual: 0
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr) << endl;
    return 0;
}
