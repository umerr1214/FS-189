#include <iostream>
using namespace std;

void sortData(int arr[], int size, char choice) {
    // Robustness Issue: No check for invalid 'choice' or null/empty array
    // If user passes 'x', nothing happens (which might be okay, but could be better)
    // Critical: arr access if size < 0 or arr is NULL
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (choice == 'a') {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else if (choice == 'd') {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int* arr = NULL;
    // Crash waiting to happen if size > 1
    // sortData(arr, 5, 'a');
    
    return 0;
}
