#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string firstName;
    std::string lastName;
    int age = 0; // Initialize age to make output predictable if cin fails

    std::cout << "Please enter your first name: ";
    std::cin >> firstName;
    std::cout << "Please enter your last name: ";
    std::cin >> lastName;

    std::cout << "Please enter your age: ";
    std::cin >> age; // Robustness issue: no validation for non-integer input

    // If 'age' input fails (e.g., user types "twenty"),
    // 'cin' will be in a fail state, and 'age' will retain its initial value (0).
    // The program will proceed without error handling.
    // This is the robustness issue.

    std::cout << "\nHello, " << firstName << " " << lastName << "!" << std::endl;
    std::cout << "You are " << age << " years old." << std::endl;

    return 0;
}