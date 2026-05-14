#include <iostream>
#include <string> // Not strictly necessary for char input, but included for potential future use or verbosity
#include <limits> // Required for std::numeric_limits

int main() {
    char theUserOption; // Readability Issue: Unclear variable name, 'theUserOption' instead of 'choice'
    int first_operand, second_operand; // Readability Issue: Underscores in variable names, not standard C++ style for local variables

    do {
        std::cout << "\n####################################################################################################\n";
        std::cout << "### Welcome to the Simple Arithmetic Menu Program! Please select one of the following operations: ###\n";
        std::cout << "### Enter 'A' to perform an Addition operation.                                                  ###\n";
        std::cout << "### Enter 'S' to perform a Subtraction operation.                                                ###\n";
        std::cout << "### Enter 'Q' to Terminate and Quit the program.                                                 ###\n";
        std::cout << "####################################################################################################\n";
        std::cout << "Your desired operation choice: "; // Readability Issue: Overly verbose menu prompt
        std::cin >> theUserOption;

        // Clear input buffer to prevent issues with subsequent inputs after an invalid character
        // This is a minimal robustness measure, but the primary issues are readability/efficiency.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (theUserOption) {
            case 'A':
            case 'a': // Readability/Efficiency Issue: Redundant checking for both cases in each switch label
                      // It would be more efficient and readable to convert input to uppercase once.
                std::cout << "You have selected the Addition operation. Please provide the first number: "; // Verbose output
                std::cin >> first_operand;
                std::cout << "Now, please provide the second number for the addition: "; // Verbose output
                std::cin >> second_operand;
                std::cout << "The outcome of your Addition operation is: " << first_operand + second_operand << std::endl << std::endl; // Excessive newlines
                break;
            case 'S':
            case 's': // Readability/Efficiency Issue: Redundant checking
                std::cout << "You have selected the Subtraction operation. Please provide the minuend (first number): "; // Verbose output
                std::cin >> first_operand;
                std::cout << "Now, please provide the subtrahend (second number) for the subtraction: "; // Verbose output
                std::cin >> second_operand;
                std::cout << "The final result of your Subtraction operation is: " << first_operand - second_operand << std::endl << std::endl; // Excessive newlines
                break;
            case 'Q':
            case 'q': // Readability/Efficiency Issue: Redundant checking
                std::cout << "You have chosen to Terminate and Quit the program. Thank you for using our service. Farewell!\n"; // Verbose output
                break;
            default:
                std::cout << "Your input '" << theUserOption << "' was not recognized as a valid menu option. Kindly review the menu and try again.\n"; // Verbose error message
                break;
        }
    } while (theUserOption != 'Q' && theUserOption != 'q'); // Readability/Efficiency Issue: Redundant check in loop condition

    return 0;
}