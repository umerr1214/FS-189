#include <iostream> // Required for input/output operations

int main() {
    int number; // Declare an integer variable to store the user's input
    std::cout << "Enter an integer: "; // Prompt the user for input
    std::cin >> number; // Read the integer from standard input

    int reversed_number = 0; // Initialize a variable to store the reversed number

    // Create a temporary variable to work with, preserving the original sign for check later.
    // Using a temporary variable avoids modifying the original 'number' input directly
    // which can be good practice, though not strictly necessary here.
    int temp_number = number;

    // Handle the sign of the number
    // If the number is negative, make it positive for digit extraction
    // and remember to add the negative sign back later.
    bool is_negative = false;
    if (temp_number < 0) {
        is_negative = true;
        // Convert to positive for reversal logic.
        // Note: Special case for INT_MIN (-2147483648) where -INT_MIN overflows int.
        // For typical inputs, this is fine. For extreme robustness, long long would be used.
        temp_number = -temp_number;
    }

    // If the input was 0, the loop below won't execute, and reversed_number will remain 0.
    // The sign handling also ensures '0' is printed correctly without a '-'
    // so no special 'if (number == 0)' check is strictly necessary for correctness,
    // making the code more concise.
    while (temp_number > 0) { // Loop as long as there are digits to process
        int digit = temp_number % 10; // Get the last digit (e.g., 123 -> 3)
        reversed_number = reversed_number * 10 + digit; // Append the digit to the reversed number (e.g., 0*10+3=3, 3*10+2=32)
        temp_number /= 10; // Remove the last digit (e.g., 123 -> 12, 12 -> 1)
    }

    // Print the result, including the negative sign if applicable
    if (is_negative) {
        std::cout << "-";
    }
    std::cout << reversed_number << std::endl;

    return 0; // Indicate successful program execution
}