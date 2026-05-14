#include <iostream> // Required for standard input/output operations
#include <limits>   // Required for std::numeric_limits

int main() {
    int size; // Declare an integer variable to store the array size

    std::cout << "Enter the size of the array: "; // Prompt the user for the array size

    // Robust input validation loop for 'size':
    // - Ensures that input is an integer.
    // - Ensures that the integer is positive.
    while (!(std::cin >> size) || size <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for the size: ";
        std::cin.clear(); // Clear any error flags on std::cin
        // Discard the rest of the invalid line from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int* arr = nullptr; // Initialize the pointer to nullptr before allocation

    try {
        arr = new int[size]; // Dynamically allocate memory for the array
    } catch (const std::bad_alloc& e) {
        // Handle potential memory allocation failure
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1; // Indicate an error and exit
    }

    std::cout << "Enter " << size << " integer values:" << std::endl; // Prompt user to fill the array
    for (int i = 0; i < size; ++i) { // Loop through each element to get user input
        std::cout << "Enter value for element " << i << ": ";

        // Robust input validation loop for each array element:
        // - Ensures that input is an integer.
        while (!(std::cin >> arr[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear any error flags on std::cin
            // Discard the rest of the invalid line from the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Array elements: "; // Print header for the array elements
    for (int i = 0; i < size; ++i) { // Loop through each element to print it
        std::cout << arr[i];
        if (i < size - 1) { // Add a space between elements, but not after the last one
            std::cout << " ";
        }
    }
    std::cout << std::endl; // Print a newline at the end of the output

    delete[] arr; // Deallocate the dynamically allocated memory
    arr = nullptr; // Set the pointer to nullptr to prevent dangling pointer issues

    return 0; // Indicate successful program execution
}