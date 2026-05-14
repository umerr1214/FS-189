#include <iostream> // Required for input/output operations (std::cout, std::cin, std::endl)
#include <string>   // Required for using std::string to store names
#include <limits>   // Required for std::numeric_limits, used in input validation

int main() {
    // Declare variables to store the user's first name, last name, and age.
    // Appropriate data types are used: std::string for names (to handle spaces) and int for age.
    std::string firstName;
    std::string lastName;
    int age;

    // Prompt the user to enter their first name.
    // std::getline is used to read the entire line, including spaces.
    // std::ws manipulator skips any leading whitespace characters (like leftover newlines from previous inputs).
    std::cout << "Enter your first name: ";
    std::getline(std::cin >> std::ws, firstName);

    // Prompt the user to enter their last name.
    // std::getline is used again to read the entire line for the last name.
    std::cout << "Enter your last name: ";
    std::getline(std::cin, lastName);

    // Prompt the user to enter their age with robust input validation.
    // A loop ensures that the program only proceeds when valid integer input is received.
    while (true) {
        std::cout << "Enter your age: ";
        std::cin >> age;

        // Check if the input operation failed (e.g., non-numeric input).
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number for age." << std::endl;
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard all characters remaining in the input buffer up to the newline character.
            // This prevents an infinite loop if invalid input remains in the buffer.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Input was successful. Discard the rest of the line (the newline character)
            // to prevent it from affecting subsequent std::getline calls if any.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Exit the loop as valid input was received.
        }
    }

    // Display a greeting message using all the collected information.
    // Direct streaming to std::cout is efficient.
    std::cout << "Hello, " << firstName << " " << lastName << ", you are " << age << " years old." << std::endl;

    return 0; // Indicate successful program execution.
}