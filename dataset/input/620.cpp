#include <iostream>
using namespace std;

void evenSort(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        // Increment left index while we see 0 at left
        while (arr[left] % 2 == 1 && left < right) // Logical Error: checking for odd (1) instead of even (0) to skip
            left++;
        
        // Decrement right index while we see 1 at right
        while (arr[right] % 2 == 0 && left < right) // Logical Error: checking for even (0) instead of odd (1) to skip
            right--;
        
        if (left < right) {
            // Swap arr[left] and arr[right]
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Intention: Evens first, Odds last.
    // Logic error implemented: It tries to keep Odds at left and Evens at right (swapped logic)
    evenSort(arr, size);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
