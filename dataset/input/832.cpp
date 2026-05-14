#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    // Robustness Issue: No NULL check.
    // Also no check for negative size.
    
    // Crash if arr is NULL
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    // Crash
    // moveZeroes(NULL, 5);
    return 0;
}
