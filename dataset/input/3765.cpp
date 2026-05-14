#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits

// Function to swap two integer values by reference
// Uses a temporary variable, which is a clear, safe, and widely preferred method.
void swapNumbers(int& num1, int& num2) {
    int temp = num1; // Store the value of num1 in a temporary variable
    num1 = num2;     // Assign the value of num2 to num1
    num2 = temp;     // Assign the stored original value of num1 to num2
}

int main() {
    int num1, num2; // Declare two integer variables

    // Prompt user for input and handle potential invalid input robustly
    std::cout << "Enter two integers: \n";
    while (!(std::cin >> num1 >> num2)) { // Loop until valid integers are read
        std::cout << "Invalid input. Please enter integers only.\n";
        std::cin.clear(); // Clear the error flags on std::cin
        // Discard all remaining characters in the input buffer up to the newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter two integers: \n"; // Re-prompt for input
    }

    // Print the values before swapping
    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    // Call the swapNumbers function to swap the values
    swapNumbers(num1, num2);

    // Print the values after swapping
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0; // Indicate successful execution
}