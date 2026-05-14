#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits for robust input handling

int main() {
    int arraySize; // Clear and descriptive variable name for the array size
    std::cout << "Enter the size of the integer array (N): ";
    std::cin >> arraySize;

    // Robust input validation for N
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter a valid integer for N." << std::endl;
        // Clear error flags and ignore remaining input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Validate that N is a positive integer
    if (arraySize <= 0) {
        std::cout << "Array size N must be a positive integer. Exiting." << std::endl;
        return 0; // Exit gracefully for non-positive size
    }

    int* dynamicArray = nullptr; // Initialize pointer to nullptr as good practice

    try {
        // Dynamically allocate memory for the integer array
        dynamicArray = new int[arraySize];
    } catch (const std::bad_alloc& e) {
        // Robustly handle memory allocation failure
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1; // Indicate an error
    }

    // Populate the array with values from 1 to N
    std::cout << "Populating array with values from 1 to " << arraySize << "..." << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        dynamicArray[i] = i + 1;
    }

    // Print the contents of the array
    std::cout << "Array contents: ";
    for (int i = 0; i < arraySize; ++i) {
        // Use '\n' for efficiency, and avoid trailing space after the last element
        std::cout << dynamicArray[i] << (i == arraySize - 1 ? "" : " ");
    }
    std::cout << std::endl; // Newline at the end of output

    // Deallocate the dynamically allocated memory
    delete[] dynamicArray;
    dynamicArray = nullptr; // Set pointer to nullptr after deallocation to prevent dangling pointer issues

    return 0; // Indicate successful execution
}