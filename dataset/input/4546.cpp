#include <iostream>
#include <algorithm> // For std::swap

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
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

    int arr2[] = {10, 20, 30, 40} // Syntax Error: Missing semicolon here
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