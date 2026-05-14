#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    // Semantic Error: Variable Length Array (VLA) usage in non-standard C++ (though GCC allows it).
    // Or pointer arithmetic confusion.
    
    // Let's use assignment in array index?
    // Let's confuse `l`, `m`, `r` indices.
    
    // Let's use:
    // int* L = &arr[l]; // Pointer to left part
    // int* R = &arr[m+1]; // Pointer to right part
    // And try to sort in place without copying? (Merge sort needs extra space).
    // If we write directly to arr[k] without copying L/R first, we overwrite needed data!
    // This is a semantic error of the algorithm logic (in-place merge is very hard/different algo).
    
    // Implementation of incorrect in-place merge attempt:
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            arr[k++] = arr[i++]; // Overwrites arr[k] which might be needed later if k > i?
            // Actually k starts at l, i starts at l.
            // arr[l] = arr[l]. i becomes l+1. k becomes l+1.
            // No problem yet.
            // But if arr[j] < arr[i]:
            // arr[l] = arr[j].
            // We just lost arr[l]!
            // This is semantically wrong for "merge" which requires buffer or rotation.
        } else {
            arr[k++] = arr[j++];
        }
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    // Expected: 5 6 7 11 12 13
    // Actual: Data corruption/loss due to in-place overwrite attempt
    mergeSort(arr, 0, 5);
    for(int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
