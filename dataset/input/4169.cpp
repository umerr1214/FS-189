#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int main() {
    std::string name;
    int age;
    double height;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    // Clear the input buffer after reading an integer, before a potential getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your height (in meters): ";
    std::cin >> height;

    // Clear the input buffer after reading a double
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Logical Error: 'age' and 'height' variables are swapped in the output sentence.
    std::cout << "Hello " << name << ", you are " << height << " years old and " << age << " meters tall." << std::endl;

    return 0;
}