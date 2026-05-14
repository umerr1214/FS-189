#include <iostream>
#include <limits> // Required for robust input handling

// Function to perform linear search
int linearSearch(const int arr[], int size, int target) {
    // Iterate through the array elements from start to end
    for (int i = 0; i < size; ++i) {
        // If the current element matches the target, return its index
        if (arr[i] == target) {
            return i; // Target found, return its index immediately
        }
    }
    // If the loop completes without finding the target, return -1
    return -1; // Target not found in the array
}

int main() {
    // Define a sample array and its size
    const int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target; // Variable to store the user-provided target

    // Display the array elements to the user
    std::cout << "Array: {";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;

    std::cout << "Enter the target element to search: ";
    // Robust input handling: Loop until a valid integer input is successfully received
    while (!(std::cin >> target)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags (e.g., failbit, badbit)
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Call the linearSearch function
    int result = linearSearch(arr, size, target);

    // Display the search result to the user
    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0; // Indicate successful program execution
}