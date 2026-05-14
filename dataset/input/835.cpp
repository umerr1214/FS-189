#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
            
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar
} // Syntax Error: Missing semicolon

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max Subarray Sum: " << maxSubArray(arr, n) << endl;
    return 0;
}
