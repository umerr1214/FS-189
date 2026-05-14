#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    // Robustness Issue: No check for NULL array.
    // Also, binary search has a potential integer overflow bug with (start + end) / 2
    // if start + end exceeds INT_MAX.
    // Correct way is start + (end - start) / 2
    
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        // Potential overflow here, though usually not hit with small arrays in homework
        // But main robustness issue is null pointer check or handling unsorted array assumption
        int mid = (start + end) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int* arr = NULL;
    // Crash
    // searchData(arr, 5, 10);
    
    return 0;
}
