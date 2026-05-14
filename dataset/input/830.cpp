#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int count = 0; 
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Logical Error: Swapping with current index 'i' instead of 'count'?
            // Or just overwriting without swapping?
            // The standard algorithm overwrites.
            
            // Let's implement a swap based logic but fail to increment count properly.
            // Or overwrite but forget to fill zeros at the end.
            
            arr[count] = arr[i];
            // count++; // Forgot to increment count!
        }
    }
    
    // Fill remaining with 0
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: 1 3 12 0 0
    // Actual with error:
    // i=1 (val 1): arr[0] = 1. count stays 0.
    // i=3 (val 3): arr[0] = 3. count stays 0.
    // i=4 (val 12): arr[0] = 12. count stays 0.
    // Loop ends.
    // Fill zeros from count(0) to n.
    // arr becomes {0, 0, 0, 0, 0}.
    
    moveZeroes(arr, n);
    
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
