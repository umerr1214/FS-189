#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // Semantic Error: bitwise operator instead of logical?
            // Or using assignment.
            
            // Let's use assignment in array index?
            // if (arr[j] < arr[min_idx])
            
            // Let's use address comparison.
            if (&arr[j] < &arr[min_idx]) { // Comparing addresses. Since j > min_idx initially, address is higher.
                // &arr[j] > &arr[min_idx]. Condition is False.
                // Does it ever swap? 
                // Addresses are increasing. &arr[j] < &arr[min_idx] is false if j > min_idx.
                // So min_idx never updates.
                // min_idx stays 'i'.
                // Swap happens: arr[i] with arr[i]. No change.
                // Array remains unsorted.
                
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: 11 12 22 25 64
    // Actual: 64 25 12 22 11 (Unsorted)
    selectionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
