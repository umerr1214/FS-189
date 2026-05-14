#include <iostream>
#include <vector>
#include <numeric> // For std::iota if needed, but not for this problem

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Robustness Issue: This loop iterates 'n' times, effectively swapping
    // elements and then swapping them back, resulting in the original array.
    // It works for n=0 or n=1 (no change), but fails to reverse for n > 1.
    // The correct loop should iterate only up to n/2.
    for (int i = 0; i < n; ++i) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // Print the modified array
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}