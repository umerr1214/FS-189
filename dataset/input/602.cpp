#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int &min, int &max, int size) {
    min = 0; // Logical error: initializing to 0 instead of a large value or first element
    max = 0; // Logical error: initializing to 0 instead of a small value or first element
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}

int main() {
    int arr[] = {10, 2, 5, 8, 1, 9};
    int min, max;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    findMinMax(arr, min, max, size);
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    
    return 0;
}
