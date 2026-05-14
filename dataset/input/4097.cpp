#include <iostream>
#include <limits> // Not strictly needed for this specific logical error, but good practice for min/max int values

int main() {
    int arr[5];
    int size = 5;

    std::cout << "Enter 5 integer values:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
    }

    // Logical error: Initializing minVal and maxVal to 0.
    // This will lead to incorrect results if all input numbers are negative (max will be 0)
    // or if all input numbers are positive and none are 0 (min will be 0).
    int maxVal = 0; // Should be initialized to arr[0] or std::numeric_limits<int>::min()
    int minVal = 0; // Should be initialized to arr[0] or std::numeric_limits<int>::max()

    for (int i = 0; i < size; ++i) { // Loop starts from 0, which is fine if initial values are global min/max
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    std::cout << "Largest element: " << maxVal << std::endl;
    std::cout << "Smallest element: " << minVal << std::endl;

    return 0;
}