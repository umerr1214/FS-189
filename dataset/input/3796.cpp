#include <iostream>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
} // Missing semicolon here, causing a syntax error

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Searching in {10, 20, 30, 40, 50}:\n";
    std::cout << "Target 30: " << linearSearch(arr1, size1, 30) << " (Expected: 2)\n";
    std::cout << "Target 10: " << linearSearch(arr1, size1, 10) << " (Expected: 0)\n";
    std::cout << "Target 50: " << linearSearch(arr1, size1, 50) << " (Expected: 4)\n";
    std::cout << "Target 99: " << linearSearch(arr1, size1, 99) << " (Expected: -1)\n";

    int arr2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "\nSearching in {5}:\n";
    std::cout << "Target 5: " << linearSearch(arr2, size2, 5) << " (Expected: 0)\n";
    std::cout << "Target 10: " << linearSearch(arr2, size2, 10) << " (Expected: -1)\n";

    return 0;
}