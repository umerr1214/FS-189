#include <iostream>
#include <string>

int main() {
    std::string usersFirstName; // Overly verbose variable name
    int usersAgeInYears;        // Overly verbose variable name
    double usersHeightInMeters; // Overly verbose variable name

    // Input prompts
    std::cout << "Enter your first name: ";
    std::cin >> usersFirstName;

    std::cout << "Enter your age: ";
    std::cin >> usersAgeInYears;

    std::cout << "Enter your height in meters: ";
    std::cin >> usersHeightInMeters;

    // Outputting the summary using multiple separate 'std::cout' statements
    // instead of chaining '<<', which is less efficient and less readable.
    std::cout << "Hello ";
    std::cout << usersFirstName;
    std::cout << ", you are ";
    std::cout << usersAgeInYears;
    std::cout << " years old and ";
    std::cout << usersHeightInMeters;
    std::cout << " meters tall.";
    std::cout << std::endl; // Using std::endl flushes the buffer, which can be less efficient than '\n'

    return 0;
}