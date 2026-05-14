#include <iostream> // Required for input/output operations

int main() {
    // Define constants for matrix dimensions for better readability and maintainability
    const int ROWS = 3;
    const int COLS = 3;

    // Declare a 3x3 integer matrix
    int matrix[ROWS][COLS];

    std::cout << "Welcome! Please enter " << ROWS * COLS << " integer elements for the "
              << ROWS << "x" << COLS << " matrix." << std::endl;

    // Loop to read elements into the matrix from the user
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "Enter element for matrix[" << i << "][" << j << "]: ";
            // Read the integer element
            std::cin >> matrix[i][j];

            // Basic input validation: check if the input operation failed
            if (std::cin.fail()) {
                std::cerr << "Invalid input. Please enter an integer." << std::endl;
                // Clear the error flags
                std::cin.clear();
                // Discard invalid input from the buffer
                std::cin.ignore(10000, '\n');
                // Decrement j to re-enter the current element
                --j;
            }
        }
    }

    std::cout << "\n--- Matrix Elements ---" << std::endl;
    // Loop to print the matrix elements
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t"; // Use tab for alignment
        }
        std::cout << std::endl; // Move to the next line after each row
    }

    std::cout << "\n--- Sum of Elements for Each Row ---" << std::endl;

    // Loop to calculate and print the sum of elements for each individual row
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0; // Initialize sum for the current row
        for (int j = 0; j < COLS; ++j) {
            rowSum += matrix[i][j]; // Add current element to rowSum
        }
        std::cout << "Row " << i << " Sum: " << rowSum << std::endl; // Print the sum for the row
    }

    return 0; // Indicate successful program execution
}