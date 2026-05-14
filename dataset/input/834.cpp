#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    if (arr == nullptr || n <= 0) return;
    
    int count = 0; // Count of non-zero elements
    
    // Traverse the array. If element encountered is non-zero, then
    // replace the element at index 'count' with this element
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    
    // Now all non-zero elements have been shifted to front and 'count' is set
    // as index of first 0. Make all elements 0 from count to end.
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    moveZeroes(arr, n);
    
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    moveZeroes(NULL, 0); // Safe
    return 0;
}
