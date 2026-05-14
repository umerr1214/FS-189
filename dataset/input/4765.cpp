#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;
    int age;

    std::cout << "Enter your first name: ";
    std::cin >> firstName; // Robustness issue: Only reads a single word. If "John Paul" is entered, firstName becomes "John", "Paul" remains in buffer.

    std::cout << "Enter your last name: ";
    // If a multi-word first name was entered, the second word will be read into lastName here,
    // effectively skipping the user's intended input for the last name.
    std::cin >> lastName;

    std::cout << "Enter your age: ";
    std::cin >> age; // Robustness issue: No error handling for non-integer input.
                     // If non-numeric input is provided, cin fails, 'age' might be uninitialized (UB) or 0,
                     // and subsequent cin operations might behave unexpectedly without clearing the fail state.

    std::cout << "Hello, " << firstName << " " << lastName << ", you are " << age << " years old." << std::endl;

    return 0;
}