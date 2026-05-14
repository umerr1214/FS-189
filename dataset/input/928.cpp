#include <iostream>
using namespace std;

// Robustness: VLA is unsafe if n is large (Stack Overflow).
// Dynamic allocation or std::vector is needed for temp arrays.

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Robustness Issue: Variable Length Arrays (VLA) usage.
    // If n1 or n2 is large, stack overflow occurs.
    // Also not standard C++.
    int L[n1]; 
    int R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    // Robustness: No check for NULL array.
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // mergeSort(NULL, 0, 5); // Crash in merge access
    
    // Large array test might crash stack due to VLA
    return 0;
}
