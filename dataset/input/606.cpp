#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int &min, int &max, int size) {
    if (size <= 0 || arr == nullptr) {
        // Handle invalid input gracefully
        // Depending on requirements, could throw exception or set error codes.
        // For this signature, we might just return without modifying or set to safe defaults.
        return; 
    }

    min = arr[0];
    max = arr[0];
    
    for (int i = 1; i < size; i++) {
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
