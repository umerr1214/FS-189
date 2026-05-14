#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;
    
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> number;
        
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear the error flag on std::cin
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            number = 0; // Set number to 0 to ensure the loop continues
        } else if (number <= 0) {
            std::cout << "Number must be positive. Please try again." << std::endl;
        }
    } while (number <= 0); // Loop continues if input is invalid (number is 0) or non-positive
    
    std::cout << "You entered a valid positive integer: " << number << std::endl;
    
    return 0;
}