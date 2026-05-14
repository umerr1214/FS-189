#include <iostream>
#include <vector>
#include <string> // For std::string, though not strictly used in this core logic

// Function containing the main logic for testing
int solve_and_print() {
    const int ARRAY_SIZE = 8;
    const int arr[ARRAY_SIZE] = {10, 20, 5, 30, 40, 50, 60, 70};
    int targetValue;
    int foundIndex = -1; // Initialize to -1 to indicate not found

    std::cout << "Enter the integer to search: ";
    std::cin >> targetValue;

    // Robust input validation
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter an integer." << std::endl;
        return 1; // Indicate an error occurred
    }

    // Perform linear search
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] == targetValue) {
            foundIndex = i; // Store the first index where it's found
            break;          // Exit loop immediately after finding the element (efficiency)
        }
    }

    // Report result
    if (foundIndex != -1) {
        std::cout << "Found at index " << foundIndex << std::endl;
    } else {
        std::cout << "Not present" << std::endl;
    }

    return 0; // Indicate successful execution
}

int main() {
    return solve_and_print();
}