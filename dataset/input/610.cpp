#include <iostream>
using namespace std;

int searchData(int arr[], int size, int key) {
    // Robustness Issue: No check for null pointer or negative size
    // While C++ arrays decay to pointers, explicit checks are good practice 
    // especially if size can be invalid.
    
    // Assuming size is correct, but what if size is negative passed by caller?
    // The loop condition i < size will be false immediately (since i=0), 
    // which is technically safe but logically incorrect if size is just wrong.
    
    // More critical: if arr is NULL.
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) { // Potential segfault if arr is NULL and size > 0
            return i;
        }
    }
    return -1;
}

int main() {
    int* arr = NULL;
    int size = 5; 
    int key = 10;
    
    // This call is dangerous and represents the robustness issue
    // int index = searchData(arr, size, key); 
    
    return 0;
}
