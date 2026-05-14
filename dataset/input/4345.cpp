#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this problem, but good practice for arrays/vectors

int main() {
    int arr[5]; // Declare an array of 5 integers

    std::cout << "Please enter 5 integer values:" << std::endl;

    // Prompt user for each element
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter value for element " << i + 1 << ": ";
        std::cin >> arr[i]; // Reads input without checking for failure
    }

    std::cout << "Array elements in reverse order:" << std::endl;

    // Print elements in reverse order
    for (int i = 4; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}