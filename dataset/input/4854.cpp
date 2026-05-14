#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    int searchNum;
    bool found = false;
    int index = -1;

    std::cout << "Enter a number to search for: ";
    std::cin >> searchNum;

    // Semantic Error: Array out-of-bounds access
    // The loop iterates from 0 to 5 (inclusive), meaning arr[5] will be accessed,
    // which is beyond the bounds of a 5-element array (valid indices are 0-4).
    for (int i = 0; i <= arr.size(); ++i) { // Should be i < arr.size()
        if (i == arr.size()) { // This check prevents crash, but arr[i] below is still UB.
                               // To make it a clear semantic error, let's remove this check
                               // and just let it access arr[5].
            // If the loop condition is i <= arr.size(), then arr[arr.size()] will be accessed.
            // This is undefined behavior.
            std::cout << "Attempting to access arr[" << i << "], which is out of bounds." << std::endl;
            break; // Break to prevent a crash, but the semantic error still occurred.
        }
        if (arr[i] == searchNum) {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        std::cout << index << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}