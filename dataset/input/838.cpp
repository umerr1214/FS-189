#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    // Robustness Issue: No NULL check.
    // If arr is NULL, crash.
    
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i]; // Crash if NULL
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main() {
    // Crash
    // maxSubArray(NULL, 5);
    return 0;
}
