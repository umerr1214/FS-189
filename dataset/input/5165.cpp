#include <iostream>

// Function definition
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        } else { // Logical error: returns -1 prematurely if current element doesn't match
            return -1;
        }
    }
    return -1; // This line is only reached if size is 0 or if the loop is empty
}

int main() {
    const int sampleArr[] = {10, 20, 30, 40, 50};
    int size = sizeof(sampleArr) / sizeof(sampleArr[0]);
    int target;

    std::cout << "Array: {10, 20, 30, 40, 50}" << std::endl;
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