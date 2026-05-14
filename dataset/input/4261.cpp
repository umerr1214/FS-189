#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits

int main() {
    int N; // Variable to store the array size
    std::cout << "Enter the size of the array (N): ";
    std::cin >> N;

    // Input validation for non-integer input
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter an integer." << std::endl;
        // Clear error flags and ignore remaining input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Basic validation for array size N
    if (N <= 0) {
        std::cout << "Array size N must be positive. Exiting." << std::endl;
        return 0; // Exit gracefully for non-positive size
    }

    // Robustness Issue: No try-catch block for std::bad_alloc.
    // If memory allocation fails for a very large N, the 'new' operator
    // will throw std::bad_alloc, causing the program to terminate abruptly
    // without a graceful error message or cleanup.
    int* arr = new int[N]; // Dynamically allocate memory

    std::cout << "Populating array..." << std::endl;
    // Populate the array with values from 1 to N
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }

    std::cout << "Array contents: ";
    // Print the contents of the array
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << (i == N - 1 ? "" : " "); // Print space between elements
    }
    std::cout << std::endl; // Newline at the end of output

    // Deallocate the dynamically allocated memory
    delete[] arr;
    // arr = nullptr; // Good practice, but not strictly required for correctness at program exit

    return 0; // Indicate successful execution
}