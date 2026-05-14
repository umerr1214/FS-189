#include <iostream>
#include <vector>
#include <algorithm> // For std::swap, though manual swap is fine too

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Correct Version: In-place array reversal using two pointers.
    // This is an efficient O(N) approach and is highly readable.
    int start = 0;
    int end = n - 1;

    while (start < end) {
        // Swap elements at start and end pointers
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers towards the center
        start++;
        end--;
    }

    // Print the modified array
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}