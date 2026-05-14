#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;
    char ageChar; // Semantic error: Using char for age, which is inappropriate for multi-digit numbers

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::cout << "Enter your age: ";
    std::cin >> ageChar; // This will only read the first character of the age input

    std::cout << "Hello, " << firstName << " " << lastName << "! You are " << ageChar << " years old.\n";

    return 0;
}