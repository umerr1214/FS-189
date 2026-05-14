#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <new>    // Required for std::bad_alloc

// Core logic function
void solve() {
    int arraySize;

    // Robust input loop for array size
    while (true) {
        std::cout << "Enter the size of the array (a positive integer): ";
        std::cin >> arraySize;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Ignore the rest of the line to prevent infinite loop with bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (arraySize <= 0) {
            std::cout << "Array size must be a positive integer." << std::endl;
        } else {
            // Valid positive integer input received
            break;
        }
    }

    int* dynamicArray = nullptr; // Initialize pointer to nullptr as good practice

    // Handle potential memory allocation failure using try-catch
    try {
        dynamicArray = new int[arraySize];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return; // Exit the function if allocation fails
    }

    std::cout << "Enter " << arraySize << " integers:" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        // Robust input loop for each array element
        while (true) {
            std::cout << "Element " << i << ": ";
            int value;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter an integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                dynamicArray[i] = value;
                break; // Valid input for element, break inner loop
            }
        }
    }

    std::cout << "\nArray contents: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray; // Deallocate the memory
    dynamicArray = nullptr; // Set pointer to nullptr after deallocation

} // end solve

int main() {
    solve();
    return 0;
}