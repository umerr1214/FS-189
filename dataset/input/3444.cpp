#include <iostream>

int main() {
    int arr[5];
    std::cout << "Enter 5 integer values:" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    int largest = arr[0];
    // Semantic Error: Loop for finding the largest element goes out of bounds.
    // The array 'arr' has valid indices from 0 to 4. When i becomes 5, arr[5] is accessed,
    // leading to undefined behavior (reading/writing memory outside the array).
    for (int i = 1; i <= 5; ++i) { // Should be i < 5
        if (arr[i] > largest) { 
            largest = arr[i];
        }
    }

    std::cout << "The largest element is: " << largest << std::endl;
    return 0;
}