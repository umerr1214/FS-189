#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;
    int age;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::cout << "Enter your age: ";
    std::cin >> age;

    // A simple check for valid age input could be added here for even greater robustness,
    // but for the given question, basic input is considered correct if not explicitly asked for loops.
    // e.g., if (std::cin.fail()) { /* handle error */ }

    std::cout << "\n--- Your Information ---" << std::endl;
    std::cout << "Name:    " << firstName << " " << lastName << std::endl;
    std::cout << "Age:     " << age << " years old" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Greeting: Hello, " << firstName << "! Welcome!" << std::endl;

    return 0;
}