#include <iostream>
using namespace std;

void binomSum(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        if (n < 0) {
            arr[i] = 0; // Handle negative numbers as 0 sum
        } else {
            arr[i] = (n * (n + 1)) / 2;
        }
    }
}

int main() {
    int arr[] = {6, 4, 1, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    binomSum(arr, size) // Syntax Error: Missing semicolon
    
    cout << "Output Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
