#include <iostream>
#include <vector>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Readability / Efficiency Issue:
    // This method repeatedly moves the last element to the front, shifting
    // all other elements. This is an O(N^2) approach, which is significantly
    // less efficient than the standard O(N) two-pointer swap method.
    // The inner loop for shifting elements makes it less readable than a simple swap.
    for (int i = 0; i < n - 1; ++i) {
        int last_val = arr[n - 1]; // Store the last element
        // Shift elements from n-2 down to i
        for (int j = n - 1; j > i; --j) {
            arr[j] = arr[j - 1];
        }
        arr[i] = last_val; // Place the stored last element at the current 'i' position
    }

    // Print the modified array
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}