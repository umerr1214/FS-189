#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    int maxSoFar = 0; // Logical Error: Initializing to 0
    int maxEndingHere = 0;
    
    // If all numbers are negative, maxSoFar should be the max single element (e.g. -1).
    // But initialized to 0, it will return 0 (empty subarray sum), which might be valid 
    // if empty subarrays are allowed, but usually "at least one number" is required.
    // Or if the problem implies non-empty subarray, 0 is wrong for {-5, -2, -9}.
    
    for (int i = 0; i < n; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, -1, -3}; // All negative
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: -1
    // Actual: 0 (because maxSoFar init to 0 and maxEndingHere resets to 0)
    cout << "Max Subarray Sum: " << maxSubArray(arr, n) << endl;
    return 0;
}
