#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    std::cout << "Enter your name (single word): ";
    std::cin >> name;

    std::cout << "Enter your age: " // Syntax Error: Missing semicolon
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}