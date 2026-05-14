#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    const int ARRAY_SIZE = 5;
    int* numbers = nullptr; // Initialize pointer to nullptr

    // Dynamically allocate memory for an array of 5 integers
    numbers = new int[ARRAY_SIZE];

    std::cout << "Enter " << ARRAY_SIZE << " integer values:\n";

    // Prompt user to enter values with robust input validation
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter value for element " << i + 1 << ": ";
        while (!(std::cin >> numbers[i])) { // Check if input failed
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter value for element " << i + 1 << ": "; // Reprompt
        }
    }

    // Print the values
    std::cout << "You entered the following values:\n";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Element " << i + 1 << ": " << numbers[i] << "\n";
    }

    // Deallocate the memory
    delete[] numbers;
    numbers = nullptr; // Set pointer to nullptr after deallocation

    return 0;
}