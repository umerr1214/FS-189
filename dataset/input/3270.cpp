#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;
    char age; // Semantic Error: 'age' should be an int to store a multi-digit number, not char

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::cout << "Enter your age: ";
    std::cin >> age; // This will only read the first character of the entered age (e.g., '2' for "25")

    std::cout << "\nHello, " << firstName << " " << lastName << "!" << std::endl;
    std::cout << "You are " << age << " years old." << std::endl; // Prints only the first digit/character of age

    return 0;
}