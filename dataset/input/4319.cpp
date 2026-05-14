#include <iostream>
#include <string>

int main() {
    std::string name;
    int age_input; // Variable to store user's age input

    std::cout << "Enter your name (single word): ";
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age_input; // User enters their age

    // Logical Error: The program prints a hardcoded age (25) instead of the user's input 'age_input'.
    std::cout << "Hello, " << name << "! You are " << 25 << " years old." << std::endl;

    return 0;
}