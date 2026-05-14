#include <iostream>
#include <string>

int main() {
    std::string name;
    int age; // Semantic Error: 'age' is declared but not initialized or assigned a value

    std::cout << "Enter your name (single word): ";
    std::cin >> name;

    // Missing prompt and input for age, e.g.:
    // std::cout << "Enter your age: ";
    // std::cin >> age;

    // 'age' is used here without being initialized, leading to undefined behavior.
    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}