#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // Robustness Issue: No NULL check.
    // Also, if n < 0, loop doesn't run, safe.
    // But NULL arr causes crash if accessed? 
    // Loop condition `i < n-1` might be false if n=0.
    
    // Crash if arr is NULL and n > 0.
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) { // Crash
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // Crash
    // selectionSort(NULL, 5);
    return 0;
}
