#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits

int main() {
    int number; // Declare an integer variable to store the user's number

    // Prompt the user to enter a number
    std::cout << "Enter a number to generate its multiplication table (1 to 10): ";

    // Read the number from the user
    std::cin >> number;

    // Input validation: Check if the input was successful
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter an integer." << std::endl;
        // Clear the error flag and ignore remaining invalid input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error by returning a non-zero exit code
    }

    // Generate and print the multiplication table from 1 to 10
    for (int i = 1; i <= 10; ++i) {
        // Calculate the product
        int product = number * i;
        // Print the multiplication expression and its result
        // Using '\n' instead of std::endl for potentially better performance
        // as it avoids flushing the buffer on each line.
        std::cout << number << " x " << i << " = " << product << '\n';
    }

    return 0; // Indicate successful execution
}