#include <iostream>
#include <limits> // Required for std::numeric_limits

// Function to swap the values of two integers using a temporary variable.
// This is the most common, readable, and robust method for swapping integer values.
void swapValues(int& a, int& b) {
    int temp = a; // Store the value of 'a' in a temporary variable
    a = b;        // Assign the value of 'b' to 'a'
    b = temp;     // Assign the original value of 'a' (stored in temp) to 'b'
}

int user_main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    // Input validation loop to ensure an integer is entered
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::cout << "Enter the second integer: ";
    // Input validation loop to ensure an integer is entered
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n--- Before swap ---" << std::endl;
    std::cout << "First integer: " << num1 << std::endl;
    std::cout << "Second integer: " << num2 << std::endl;

    swapValues(num1, num2); // Call the swap function

    std::cout << "\n--- After swap ---" << std::endl;
    std::cout << "First integer: " << num1 << std::endl;
    std::cout << "Second integer: " << num2 << std::endl;

    return 0;
}