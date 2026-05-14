#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    // Readability/Efficiency Issue: Recursive implementation for Binary Search
    // while acceptable, it uses O(log N) stack space compared to O(1) for iterative.
    // Also, this specific implementation might be reconstructing the recursion poorly
    // passing arrays by pointer is fine, but if we were copying it would be bad.
    
    // Let's implement a recursive helper inside or just standard recursive logic
    // but denote it as less efficient due to stack overhead for this simple problem.
    
    if (size == 0) return -1;
    
    int mid = size / 2;
    if (arr[mid] == key) return mid;
    
    if (key < arr[mid]) {
        return searchData(arr, mid, key);
    } else {
        int result = searchData(arr + mid + 1, size - mid - 1, key);
        if (result == -1) return -1;
        return mid + 1 + result;
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, 10, 34, 40, 44, 51, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 40;
    
    int index = searchData(arr, size, key);
    
    if (index != -1) {
        cout << key << " found at index " << index << endl;
    } else {
        cout << key << " not found" << endl;
    }
    
    return 0;
}
