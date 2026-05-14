#include <iostream>
#include <array>    // Using std::array for fixed-size array
#include <limits>   // For std::numeric_limits

int main() {
    const int ARRAY_SIZE = 5;
    std::array<int, ARRAY_SIZE> numbers; // Declare std::array of size 5

    std::cout << "Enter " << ARRAY_SIZE << " integer values for the array:\n";

    // Allow user to input values into the array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter value " << i + 1 << ": ";
        // Input validation for robustness (optional for "Correct Version" unless explicitly asked, but good practice)
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // If the array is empty (not possible with fixed size 5), handle it.
    // For a size 5 array, we can safely initialize min/max with the first element.
    int largest = numbers[0];
    int smallest = numbers[0];

    // Iterate through the array to find largest and smallest elements in a single pass
    for (int i = 1; i < ARRAY_SIZE; ++i) { // Start from second element
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    // Print the largest and smallest elements
    std::cout << "Largest: " << largest << '\n';
    std::cout << "Smallest: " << smallest << '\n';

    return 0;
}