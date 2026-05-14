#include <iostream>
#include <vector> // Although not strictly necessary for fixed-size arrays, it's a common C++ practice.

int main() {
    const int ARRAY_SIZE = 5; // Use a named constant for array size for better readability and maintainability
    int numbers[ARRAY_SIZE];  // Declare an array of ARRAY_SIZE integers

    std::cout << "Please enter " << ARRAY_SIZE << " integer values:" << std::endl;

    // Prompt user to enter values for each element
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter value for element " << i + 1 << ": ";
        // Robust input: Check if input was successful
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();                                  // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    std::cout << "Array elements in reverse order:" << std::endl;

    // Print elements of the array in reverse order
    for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}