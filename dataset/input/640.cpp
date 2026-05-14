#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    // Robustness Issue: No check for null pointer.
    // Also, integer overflow if arr[i] is large. 
    // n * (n+1) can exceed INT_MAX if n approx > 46340.
    // Using 'long long' for intermediate calculation would be safer.
    
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        if (n < 0) {
            arr[i] = 0; 
        } else {
            // Potential overflow here for large n
            arr[i] = (n * (n + 1)) / 2; 
        }
    }
}

int main() {
    int* arr = NULL;
    // Crash
    // binomSum(arr, 5);
    
    // Overflow test (if int is 32-bit)
    // int arr2[] = {50000}; 
    // binomSum(arr2, 1);
    
    return 0;
}
