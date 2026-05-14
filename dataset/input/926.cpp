#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    // Logical Error: Incorrect base case or recursive steps.
    // E.g. Missing base case check `if (l < r)`.
    // Infinite recursion if l >= r.
    
    // Or incorrect mid calculation? `m = (l+r)/2` is risky for overflow but functionally okay for small arrays.
    // Or recursive calls overlap? `mergeSort(arr, l, m)` and `mergeSort(arr, m, r)`? (Infinite recursion if m=l)
    
    int m = l + (r - l) / 2;
    
    // Missing base case `if (l < r)`: will recurse infinitely or crash stack.
    // But let's assume we have it but wrong logic?
    
    if (l < r) {
        mergeSort(arr, l, m);
        // Logical Error: Calling mergeSort on `m` instead of `m+1` for second half
        // mergeSort(arr, m, r); // Overlaps! Infinite recursion on (0, 0) if l=0, m=0? No.
        // If l=0, r=1. m=0.
        // mergeSort(0, 0) -> ok.
        // mergeSort(0, 1) -> infinite recursion!
        mergeSort(arr, m, r); // Should be m+1, r
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13};
    // Stack Overflow expected
    mergeSort(arr, 0, 2);
    return 0;
}
