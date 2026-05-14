#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int arr[], int n) {
    if (arr == nullptr || n <= 1) return;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
    }
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    selectionSort(arr1, n1);
    cout << "Sorted 1: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    int arr2[] = {5, 4, 3, 2, 1};
    selectionSort(arr2, 5);
    cout << "Sorted 2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    selectionSort(NULL, 0); // Safe
    return 0;
}
