#include <iostream>
#include <algorithm> // For std::swap

// Function to reverse an array.
// Semantic error: 'arr' is passed as a pointer (int*), so 'sizeof(arr)' inside the function
// yields the size of the pointer itself (e.g., 8 bytes on a 64-bit system), not the size of the array.
// This results in an incorrect calculation for 'n_incorrect' (e.g., 8/4 = 2, instead of 5),
// leading to an incomplete reversal.
void reverseArray(int arr[]) { // arr decays to int* here
    int n_incorrect = sizeof(arr) / sizeof(arr[0]); // This is the semantic error.
                                                     // n_incorrect will be sizeof(int*) / sizeof(int)
                                                     // e.g., 8/4 = 2 (on 64-bit) or 4/4 = 1 (on 32-bit)

    int start = 0;
    int end = n_incorrect - 1; // Loop bounds are incorrect due to wrong n_incorrect

    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
    // For n_incorrect = 2, only arr[0] and arr[1] will be swapped.
    // For n_incorrect = 1, no swaps will occur.
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // Correctly calculates n as 5 in main scope

    reverseArray(arr); // Call the function with the semantic error

    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) { // Prints using the correct n for the array
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}