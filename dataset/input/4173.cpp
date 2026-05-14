#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string and std::getline

// This 'main' function has been renamed to 'student_main_logic' for testing purposes.
// In a typical standalone execution, this would be 'int main()'.
int student_main_logic() {
    std::string userName;   // Descriptive variable name for user's name
    int userAge;            // Descriptive variable name for user's age
    double userHeight;      // Descriptive variable name for user's height

    // Prompt for the name first. This is a common best practice to avoid
    // input buffer issues (like a leftover newline) that can occur when
    // mixing std::cin >> type and std::getline.
    std::cout << "Please enter your name: ";
    std::getline(std::cin, userName); // Reads the entire line, including spaces.

    std::cout << "Please enter your age: ";
    std::cin >> userAge;

    // No std::cin.ignore() is needed here because the next input operation
    // is also a numeric extraction (std::cin >> double), which handles leading
    // whitespace (including newlines) automatically. If a std::getline
    // were to follow, std::cin.ignore() would be necessary.

    std::cout << "Please enter your height (in meters): ";
    std::cin >> userHeight;

    // Print the collected information in a clear, formatted sentence.
    // Using '\n' for newlines is generally more efficient than std::endl,
    // as it doesn't force a buffer flush unless explicitly required.
    std::cout << "\nHello, " << userName << "! You are " << userAge
              << " years old and " << userHeight << " meters tall.\n";

    return 0;
}