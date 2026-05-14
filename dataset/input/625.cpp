#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1
} // Syntax Error: Missing semicolon

int main() {
    int arr[] = {-1, 0, 1, 2, 10, 34, 40, 44, 51, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 40;
    
    int index = searchData(arr, size, key);
    
    if (index != -1) {
        cout << key << " found at index " << index << endl;
    } else {
        cout << key << " not found" << endl;
    }
    
    return 0;
}
