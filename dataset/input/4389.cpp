#include <iostream> // Required for input/output operations
#include <limits>   // For std::numeric_limits, used in robust input handling
#include <string>   // For std::string, though not strictly needed for this pattern, good practice for robust input

int main() {
    int N; // Declare an integer variable to store the number of rows

    // Prompt the user to enter the number of rows
    std::cout << "Enter the number of rows (N): ";

    // Robust input handling: Ensure N is a valid non-negative integer
    while (!(std::cin >> N) || N < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer for N: ";
        std::cin.clear(); // Clear the error flags on std::cin
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Outer loop iterates from 1 to N, controlling the number of rows
    for (int row = 1; row <= N; ++row) {
        // Inner loop iterates from 1 to the current 'row' number, printing stars
        for (int col = 1; col <= row; ++col) {
            std::cout << "*"; // Print a star
        }
        // After printing all stars for the current row, move to the next line
        std::cout << '\n'; // Use '\n' for efficiency, avoiding unnecessary buffer flush
    }

    return 0; // Indicate successful program execution
}