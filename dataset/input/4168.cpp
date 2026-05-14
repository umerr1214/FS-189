#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int main() {
    std::string name;
    int age;
    double height;

    std::cout << "Enter your name: " // Syntax Error: Missing semicolon
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    // Clear the input buffer after reading an integer, before a potential getline
    // Not strictly needed here as no getline follows, but good practice
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your height (in meters): ";
    std::cin >> height;

    // Clear the input buffer after reading a double
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Hello " << name << ", you are " << age << " years old and " << height << " meters tall." << std::endl;

    return 0;
}