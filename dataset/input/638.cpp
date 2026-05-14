#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        // Logical Error: Incorrect formula for sum of 1 to n
        // Instead of n*(n+1)/2, let's use n*n or something else wrong
        arr[i] = n * n; // Calculates square instead of sum
    }
}

int main() {
    int arr[] = {6, 4, 1, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Expected: 21 10 1 6 0
    // Actual with error: 36 16 1 9 0
    binomSum(arr, size);
    
    cout << "Output Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
