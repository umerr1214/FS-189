#include <iostream>
using namespace std;

void mergeArrays(const int arr1[], int n1, const int arr2[], int n2, int result[]) {
    // Robustness Issue: No NULL check for arrays.
    // No check for negative sizes.
    // No check if 'result' is large enough (impossible to check in C without passing size).
    
    // Crash if arr1 or arr2 is NULL
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

int main() {
    // Crash
    // mergeArrays(NULL, 5, NULL, 5, NULL);
    return 0;
}
