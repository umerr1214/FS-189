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

    // Logical Error: Swapping first and last name in the greeting message
    std::cout << "\nHello, " << lastName << " " << firstName << "!" << std::endl;
    std::cout << "You are " << age << " years old." << std::endl;

    return 0;
}