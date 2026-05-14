#include <iostream>
using namespace std;

void evenSort(int arr[], int size) {
    // Robustness Issue: No checks for null pointer or negative size.
    // Also, assumes array contains only positive integers? 
    // (Modulo with negative numbers in C++ works, but behavior might be surprising if not handled, 
    // though % 2 == 0 is fine for negatives too (-2 % 2 is 0)).
    // Main robustness issue: Pointer validity.
    
    int j = -1;
    for (int i = 0; i < size; i++) {
        // If even element
        if (arr[i] % 2 == 0) {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    int* arr = NULL;
    // Crash
    // evenSort(arr, 5);
    
    return 0;
}
