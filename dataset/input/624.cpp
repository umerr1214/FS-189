#include <iostream>
using namespace std;

void evenSort(int arr[], int size) {
    if (arr == nullptr || size <= 0) {
        return;
    }

    // Lomuto partition scheme variation
    // Place evens at the beginning
    int j = -1; // Last index of even numbers found so far
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    evenSort(arr, size);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
