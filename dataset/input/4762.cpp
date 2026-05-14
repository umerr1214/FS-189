#include <iostream>
#include <string>

int main() {
    std::string firstName;
    std::string lastName;
    int age;

    std::cout << "Enter your first name: " // Syntax Error: Missing semicolon
    std::cin >> firstName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << firstName << " " << lastName << "! You are " << age << " years old.\n";

    return 0;
}