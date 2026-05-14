#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

int main() {
    std::string name;
    int age;
    int height; // Semantic Error: 'height' should be a double, but is declared as an int.

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    // Clear the input buffer after reading an integer, before a potential getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your height (in meters): ";
    // Reading a double value into an int variable causes truncation,
    // losing the decimal part and misrepresenting the height.
    std::cin >> height;

    // Clear the input buffer after reading an integer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Hello " << name << ", you are " << age << " years old and " << height << " meters tall." << std::endl;

    return 0;
}