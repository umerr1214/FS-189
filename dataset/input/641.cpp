#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    // Efficiency Issue: Using a loop to calculate sum 1..N for each element
    // instead of the O(1) formula n*(n+1)/2.
    // This makes the complexity O(N * MaxVal) or O(Sum of values) instead of O(N).
    
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        if (n < 0) {
            arr[i] = 0;
            continue;
        }
        
        int sum = 0;
        for (int k = 1; k <= n; k++) {
            sum += k;
        }
        arr[i] = sum;
    }
}

int main() {
    int arr[] = {6, 4, 1, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    binomSum(arr, size);
    
    cout << "Output Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
