#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        // Semantic Error: Modifying the loop variable 'i' or using it incorrectly?
        // Let's modify 'size' inside loop? No, that's logical.
        // Let's use bitwise operator where arithmetic is expected?
        // Or type confusion.
        
        // Semantic error: Integer division happening before multiplication? 
        // No, that's logical/precedence.
        
        // Let's confuse index with value again?
        arr[i] = (i * (i + 1)) / 2; // Using index 'i' instead of value 'arr[i]' (n)
    }
}

int main() {
    int arr[] = {6, 4, 1, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: 21 10 1 6 0
    // Actual: Sum of indices 0, 1, 2, 3, 4 -> 0, 1, 3, 6, 10
    binomSum(arr, size);
    
    cout << "Output Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
