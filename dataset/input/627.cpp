#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        // Semantic Error: Assignment instead of comparison
        if (arr[mid] = key) { 
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
    int key = 40;
    
    // Assignment in if condition modifies the array and returns true (unless key is 0)
    // It will likely return the first mid index it calculates
    int index = searchData(arr, size, key);
    
    if (index != -1) {
        cout << key << " found at index " << index << endl;
    } else {
        cout << key << " not found" << endl;
    }
    
    return 0;
}
