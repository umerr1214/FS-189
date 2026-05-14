#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n) {
    // Efficiency/Readability: Brute force O(N^3) or O(N^2).
    // Checking all subarrays.
    
    int maxSoFar = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            if (currentSum > maxSoFar) {
                maxSoFar = currentSum;
            }
        }
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max Subarray Sum: " << maxSubArray(arr, n) << endl;
    return 0;
}
