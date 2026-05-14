#include <iostream>
#include <algorithm> // For std::swap

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        // Logical Error: Incorrect index for the element at the end.
        // It should be arr[size - 1 - i], but it's arr[size - i].
        // This causes an out-of-bounds access at arr[size] when i=0 (for size > 0),
        // and swaps elements incorrectly, leading to an improperly reversed array.
        std::swap(arr[i], arr[size - i]);
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array 1: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr1, size1);

    std::cout << "Reversed array 1: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    int arr2[] = {10, 20, 30, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Original array 2: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr2, size2);

    std::cout << "Reversed array 2: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}