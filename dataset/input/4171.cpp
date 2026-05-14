#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits, though not directly used in the problematic part

// This 'main' function has been renamed to 'student_main_logic' for testing purposes.
// In a typical standalone execution, this would be 'int main()'.
int student_main_logic() {
    std::string name;
    int age;
    double height;

    std::cout << "Please enter your age: ";
    std::cin >> age; // Reads age, but leaves the newline character in the input buffer.

    std::cout << "Please enter your height (in meters): ";
    std::cin >> height; // Reads height, but also leaves the newline character in the input buffer.

    // This is a common robustness issue: std::getline is called immediately after
    // std::cin >> numeric_type. The std::getline reads the leftover newline from
    // the previous std::cin >> operation and interprets it as an empty input for 'name',
    // skipping the actual prompt for the user's name.
    // The program doesn't handle this input buffer issue, leading to an empty name.
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name); // Reads the leftover newline, 'name' becomes empty.

    // If non-numeric input was provided for age or height, std::cin would enter a fail state.
    // This program does not check for std::cin.fail() or clear the error state,
    // which is another robustness concern. In such cases, age/height might remain 0
    // (if default initialized) or contain garbage, and subsequent operations might fail.

    std::cout << "\nHello, " << name << "! You are " << age << " years old and " << height << " meters tall.\n";

    return 0;
}