#include <iostream>
#include <iomanip> // For formatting doubles, though not strictly required by this robust template

// Function template to print array elements
template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "Array elements: ";
    // Robustness issue: Off-by-one error in loop condition.
    // The loop iterates from 0 to 'size' inclusive, attempting to access arr[size],
    // which is one element beyond the valid array bounds (0 to size-1).
    // If size is 0, it will attempt to access arr[0].
    for (int i = 0; i <= size; ++i) { // ERROR: Should be i < size
        // This condition attempts to prevent the out-of-bounds print,
        // but the loop still attempts to iterate one element too far.
        // For a clearer robustness issue, we will directly print arr[i].
        // The actual behavior for arr[size] is undefined.
        if (i < size) {
            std::cout << arr[i];
            if (i < size - 1) { // Add space only if not the last valid element
                std::cout << " ";
            }
        } else {
            // This branch is taken when i == size.
            // Attempting to access arr[size] here is an out-of-bounds access.
            // For demonstration, we'll print a marker indicating this attempt.
            // In a real scenario, this would lead to undefined behavior (crash, garbage value).
            // For simplicity, let's remove the if and make it directly access arr[i]
            // as this is a more direct robustness issue.
            // The original intent of this problem is to show the loop condition itself is flawed.
            // Let's revert to a simpler out-of-bounds access.
            // Removing the if (i < size) check inside the loop to make the robustness issue more direct.
        }
    }
    // Corrected robustness issue: The loop below directly causes out-of-bounds access.
    // The previous code was too defensive.
    for (int i = 0; i <= size; ++i) { // ERROR: Should be i < size
        if (i > 0) {
            std::cout << " "; // Add space before subsequent elements
        }
        // This line will attempt to access arr[size] when i == size, leading to out-of-bounds access.
        std::cout << arr[i];
    }
    std::cout << "\n";
}

int main() {
    // Demonstrate with an array of integers
    int intArray[] = {10, 20, 30};
    printArray(intArray, 3);

    // Demonstrate with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    printArray(doubleArray, 4);

    // Demonstrate with an array of characters
    char charArray[] = {'a', 'b', 'c'};
    printArray(charArray, 3);

    // Demonstrate with an empty array
    int emptyArray[] = {};
    printArray(emptyArray, 0);

    return 0;
}