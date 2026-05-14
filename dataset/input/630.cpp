#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    if (arr == nullptr || size <= 0) {
        return -1;
    }

    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        // Prevent integer overflow for large indices
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {-1, 0, 1, 2, 10, 34, 40, 44, 51, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int key1 = 40;
    int index1 = searchData(arr, size, key1);
    if (index1 != -1) cout << key1 << " found at index " << index1 << endl;
    else cout << key1 << " not found" << endl;

    int key2 = 999;
    int index2 = searchData(arr, size, key2);
    if (index2 != -1) cout << key2 << " found at index " << index2 << endl;
    else cout << key2 << " not found" << endl;
    
    return 0;
}
