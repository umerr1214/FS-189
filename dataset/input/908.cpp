#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // Logical Error: Incorrect comparison operator.
            // Finds the MAXIMUM element instead of MINIMUM, sorting in descending order.
            if (arr[j] > arr[min_idx]) { 
                min_idx = j;
            }
        }
        // Swapping max element to the front
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: 11 12 22 25 64
    // Actual: 64 25 22 12 11 (Descending)
    selectionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
