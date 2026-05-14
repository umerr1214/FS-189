#include <iostream>

// Function definition
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int sampleArr[] = {10, 20, 30, 40, 50};
    int size = sizeof(sampleArr) / sizeof(sampleArr[0]);
    int target;

    std::cout << "Array: {10, 20, 30, 40, 50}" << std::endl // Missing semicolon here
    std::cout << "Enter target element to search: ";
    std::cin >> target;

    int index = linearSearch(sampleArr, size, target);

    if (index != -1) {
        std::cout << "Target " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}