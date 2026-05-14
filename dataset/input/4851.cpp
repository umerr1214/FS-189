#include <iostream>
#include <limits> // Required for std::numeric_limits

// Function to display the menu
void displayMenu() {
    std::cout << "--- Menu ---\n";
    std::cout << "1. Say Hello\n";
    std::cout << "2. Say Goodbye\n";
    std::cout << "3. Exit\n";
    std::cout << "--------------\n";
    std::cout << "Enter your choice: ";
}

// Function to get a valid integer choice from the user
int getChoice() {
    int choice;
    while (!(std::cin >> choice)) { // Check if input operation failed (e.g., non-integer input)
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input from the buffer until a newline character is found
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Discard any remaining characters on the line after a valid integer was read
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int main() {
    const int SAY_HELLO = 1;
    const int SAY_GOODBYE = 2;
    const int EXIT_OPTION = 3;

    int userChoice;

    do {
        displayMenu();
        userChoice = getChoice();

        switch (userChoice) {
            case SAY_HELLO:
                std::cout << "Hello, dear user!\n";
                break;
            case SAY_GOODBYE:
                std::cout << "Goodbye, for now!\n";
                break;
            case EXIT_OPTION:
                std::cout << "Exiting the program. Thank you for using it!\n";
                break;
            default:
                std::cout << "Choice " << userChoice << " is not a valid option. Please choose between 1 and 3.\n";
                break;
        }
        std::cout << "\n"; // Add a newline for better readability between menu displays
    } while (userChoice != EXIT_OPTION);

    return 0;
}