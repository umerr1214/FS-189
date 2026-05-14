#include <iostream>
#include <algorithm> // For std::swap

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // n is 5

    // Logical error: The loop iterates for 'n' times instead of 'n/2' times.
    // This causes elements to be swapped once (e.g., arr[0] with arr[4]),
    // and then swapped back to their original positions (e.g., arr[4] with arr[0])
    // when 'i' passes 'n/2', resulting in the original array.
    for (int i = 0; i < n; ++i) { // Incorrect loop condition: should be i < n / 2
        std::swap(arr[i], arr[n - 1 - i]);
    }

    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}