#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findConsecutiveZeros(const char arr[]) {
    int maxZeros = 0;
    int currentZeros = 0;
    
    for (int i = 0; arr[i] != '\0'; i++) {
        // Semantic Error: Confusing integer 0 with character '0'
        if (arr[i] == 0) { // Checks for null terminator instead of '0' character
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
    const char arr[] = "10010001";
    // Expected: 3
    // Actual: 0 because loop terminates when arr[i] == 0 ('\0') and body never matches 0 inside loop before termination.
    cout << "Max Consecutive Zeros: " << findConsecutiveZeros(arr) << endl;
    return 0;
}
