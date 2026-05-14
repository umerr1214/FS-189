#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    if (arr == nullptr || n <= 0) return 0; // Or specific error code/behavior
    
    int maxSoFar = arr[0]; // Initialize with first element to handle all-negative case correctly
    int maxEndingHere = arr[0];
    
    for (int i = 1; i < n; i++) {
        // Either extend previous subarray or start new one at current element
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main() {
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Sum 1: " << maxSubArray(arr1, 9) << endl; // 6
    
    int arr2[] = {-1, -2, -3};
    cout << "Max Sum 2: " << maxSubArray(arr2, 3) << endl; // -1
    
    cout << "Max Sum 3: " << maxSubArray(NULL, 0) << endl; // 0
    
    return 0;
}
