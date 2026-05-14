#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    int number;
    std::cout << "Please enter an integer: ";
    
    // Robust input handling: check if the input operation was successful
    if (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        // Clear error flags on std::cin and discard the invalid input from the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error by returning a non-zero status
    }

    // Determine if the number is positive, negative, or zero
    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // The only remaining possibility is number == 0
        std::cout << "The number is zero." << std::endl;
    }

    return 0; // Indicate successful execution
}