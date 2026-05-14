#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    unsigned int num; // Semantic error: Using unsigned int for input that might include negative numbers
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;

        // If non-numeric or negative input for unsigned int, cin will fail
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            num = 0; // Reset num to 0 so the loop continues
        }
    } while (num <= 0); // With unsigned int, num can never be < 0, so this is effectively num == 0

    std::cout << "You entered: " << num << std::endl;

    return 0;
}