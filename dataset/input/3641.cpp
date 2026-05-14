#include <iostream>

int main() {
    int arr[8];
    std::cout << "Enter 8 integers for the array: ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the integer to search for: ";
    std::cin >> target;

    int found_index = -1;
    for (int i = 0; i < 8; ++i) {
        // Logical Error: Searching for target + 1 instead of target
        if (arr[i] == target + 1) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        std::cout << "Element found at index: " << found_index << std::endl;
    } else {
        std::cout << "Element not present." << std::endl;
    }

    return 0;
}