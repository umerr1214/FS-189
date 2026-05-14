#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++) {
        // Semantic Error: Confusion between bitwise and arithmetic operators?
        // Or using pointer subtraction?
        
        // Let's use bitwise OR instead of addition?
        // maxEndingHere = maxEndingHere | arr[i]; 
        // This is valid syntax but semantically garbage for summing.
        
        // Let's try:
        maxEndingHere += arr[i];
        
        // Semantic Error: Comparison chaining?
        // if (0 < maxEndingHere < maxSoFar) // Valid syntax in C++ ( (0<max) < maxSoFar )
        // -> (bool < int). Often true if maxSoFar > 1.
        // It doesn't mean "maxEndingHere is between 0 and maxSoFar".
        
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
            
        // Semantic error here: assignment in condition again?
        if (maxEndingHere = 0) { // Assigns 0, returns false.
             // Never executed.
             // maxEndingHere becomes 0.
             // Effectively resets sum every iteration.
        }
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Expected: 6
    // Actual: With `maxEndingHere = 0` every loop, it basically checks max of individual elements?
    // i=0: sum=-2. if(-2=0) false. maxSoFar updated if -2 > MIN.
    // maxEndingHere reset to 0.
    // It basically calculates max element.
    // For this array, max element is 4. Max Subarray is 6.
    
    cout << "Max Subarray Sum: " << maxSubArray(arr, n) << endl;
    return 0;
}
