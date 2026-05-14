#include <iostream>     // Required for input/output operations
#include <vector>       // Using std::vector for dynamic array (though fixed size here)
#include <limits>       // Required for std::numeric_limits to clear input buffer

int main() {
    // Declare a vector to store 10 integer values
    std::vector<int> numbers(10);

    std::cout << "Please enter 10 integer values:" << std::endl;

    // Read 10 integers from the user with robust input validation
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        // Loop until valid integer input is received
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Check if the array is empty (good practice for general cases, though fixed size 10 here)
    if (numbers.empty()) {
        std::cout << "No elements to process." << std::endl;
        return 1; // Indicate an error
    }

    // Initialize max_val and min_val with the first element of the array.
    // This is a robust initialization that works correctly even with negative numbers.
    int max_val = numbers[0];
    int min_val = numbers[0];

    // Iterate through the rest of the array (from the second element)
    // to find the largest and smallest elements in a single pass for efficiency.
    for (int i = 1; i < 10; ++i) {
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
    }

    // Print the largest and smallest elements
    std::cout << "Largest element in the array: " << max_val << std::endl;
    std::cout << "Smallest element in the array: " << min_val << std::endl;

    return 0; // Indicate successful execution
}